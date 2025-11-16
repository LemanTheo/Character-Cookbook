
## Pour mettre à jour les librairies :

```sh
git submodule update --remote --merge
```

Ou de manière plus sécurisé :

```sh
git submodule update --remote
```

Et commit les modules mis à jour :

```sh
git add extern/
git commit -m "Update submodules"
```

