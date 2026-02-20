# MAT101 Project 1 (GitHub Classroom version) — Applied Arithmetic Problems

## What you edit
- `src/exercises.cpp` (implement the TODO functions)

## What you do NOT edit
- `include/exercises.h`
- `tests/` (unit tests)
- `scripts/` (CI scripts)
- `CMakeLists.txt`

Your marks are based on automated tests. After you pass tests, you will do a short interview with the instructor.

## Build (Visual Studio 2022)
This repo is CMake-based.
- Visual Studio: **File → Open → Folder...** (open this repo root)
- Or: **File → Open → CMake...** and select `CMakeLists.txt`

## Build (command line)
```bash
cmake -S . -B build
cmake --build build --config Release
```

## Run tests (command line)
```bash
ctest --test-dir build --output-on-failure
```

## Run the app (optional)
```bash
./build/mat101_app
```

## Run a single exercise suite (helps debugging)
Each exercise is a doctest suite: `A1`, `A2`, ..., `B10_prime`, `B10_range`.

```bash
bash ./scripts/test_suite.sh A1
bash ./scripts/test_suite.sh B10_prime
```
