cmake_minimum_required(VERSION 3.16)
project(mat101_project1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Warnings
if (MSVC)
  add_compile_options(/W3)
else()
  add_compile_options(-Wall -Wextra -pedantic)
endif()

add_library(mat101
  src/exercises.cpp
)
target_include_directories(mat101 PUBLIC include)

add_executable(mat101_app src/main.cpp)
target_link_libraries(mat101_app PRIVATE mat101)

# -------------------
# Tests
# -------------------
enable_testing()

add_executable(mat101_tests
  tests/test_exercises.cpp
)
target_link_libraries(mat101_tests PRIVATE mat101)
target_include_directories(mat101_tests PRIVATE tests)

add_test(NAME mat101_tests COMMAND mat101_tests)
