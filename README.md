# Projet Compilation 2022

[![Build and run tests / benchs](https://github.com/FelixLusseau/SoStoMIPS/actions/workflows/build_and_tests.yml/badge.svg)](https://github.com/FelixLusseau/SoStoMIPS/actions/workflows/build_and_tests.yml)

[![Author](https://img.shields.io/badge/author-@LouiseCouture-blue)](https://github.com/LouiseCouture)
[![Author](https://img.shields.io/badge/author-@AymaneElmahi-blue)](https://github.com/AymaneElmahi)
[![Author](https://img.shields.io/badge/author-@FelixLusseau-blue)](https://github.com/FelixLusseau)
[![Author](https://img.shields.io/badge/author-@OussamaTakiAmrani-blue)](https://github.com/oussama-taki-amrani)

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
qui compile et exécute le code de nos tests avec Spim si installé.

ou
```bash
make benchs_mips
```
qui compile et exécute le code des benchmarks du projet avec Spim si installé.