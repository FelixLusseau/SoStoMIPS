# Projet Compilation 2022

![https://git.unistra.fr/flusseau/projet-compilation-2022/-/pipelines](https://git.unistra.fr/flusseau/projet-compilation-2022/badges/main/pipeline.svg)

Compilateur pour le langage SoS vers MIPS écrit en C.

## Compilation

```bash
make
```

## Exécution

```bash
./bin/sos [--version | -v] [--tos | -t] [(--output | -o) <name>] [--help | -h] < "SoS_program"
```

## Tests

```bash
make test
```
ou
```bash
make test_mips
```
qui compile et exécute le code avec Spim si installé.