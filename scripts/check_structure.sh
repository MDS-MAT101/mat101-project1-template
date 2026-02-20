#!/usr/bin/env bash
set -euo pipefail

# Required files/folders
req=(
  "CMakeLists.txt"
  "README.md"
  "include/exercises.h"
  "src/exercises.cpp"
  "src/main.cpp"
  "tests/test_exercises.cpp"
  "scripts/build.sh"
  "scripts/test_suite.sh"
)

for f in "${req[@]}"; do
  if [[ ! -e "$f" ]]; then
    echo "Missing required file: $f"
    exit 1
  fi
done

echo "Structure OK"
