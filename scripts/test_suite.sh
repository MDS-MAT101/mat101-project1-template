#!/usr/bin/env bash
set -euo pipefail

suite="${1:-}"
if [[ -z "$suite" ]]; then
  echo "Usage: $0 <SUITE_NAME>"
  exit 2
fi

# Ensure built
cmake -S . -B build
cmake --build build --config Release

# Run only the requested suite
./build/mat101_tests --test-suite="$suite"
