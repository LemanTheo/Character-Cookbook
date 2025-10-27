cmake_minimum_required(VERSION 3.16)
project(DnDCharacterBuilder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------
# Source files
# ------------------------------
file(GLOB SRC_FILES src/*.cpp)

# Dear ImGui sources (core + backends)
set(IMGUI_SRC
    extern/imgui/imgui.cpp
    extern/imgui/imgui_draw.cpp
    extern/imgui/imgui_tables.cpp
    extern/imgui/imgui_widgets.cpp
    extern/imgui/backends/imgui_impl_glfw.cpp
    extern/imgui/backends/imgui_impl_opengl3.cpp
)

# ------------------------------
# Find external dependencies
# ------------------------------

# GL3W (system package or installed library)
include_directories(${CMAKE_SOURCE_DIR}/extern/gl3w)

# GLFW (system package or installed library)
find_package(glfw3 3.3 REQUIRED)

# nlohmann/json (header-only)
add_subdirectory(extern/nlohmann_json)

# ------------------------------
# Executable
# ------------------------------
add_executable(DnDBuilder
    ${SRC_FILES}
    ${IMGUI_SRC}
)

target_include_directories(DnDBuilder PRIVATE
    src
    extern/imgui
    extern/imgui/backends
)

target_link_libraries(DnDBuilder
    glfw
    nlohmann_json::nlohmann_json
)

# ------------------------------
# Platform-specific flags
# ------------------------------
if (UNIX AND NOT APPLE)
    target_link_libraries(DnDBuilder GL)
endif()

if (WIN32)
    # Make sure MinGW links to OpenGL
    find_package(OpenGL REQUIRED)
    target_link_libraries(DnDBuilder ${OPENGL_LIBRARIES})
endif()

message(STATUS "CMake configuration completed successfully !")
