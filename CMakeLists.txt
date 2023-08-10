cmake_minimum_required(VERSION 3.10.2)

project(S21Matrix)
include(FetchContent)
FetchContent_Declare(
    googletest

    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0 -std=c++17 -Wall -Werror -Wextra")

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
    s21_matrix_oop
    lib/s21_calc_complements.cc 
    lib/s21_determinant.cc 
    lib/s21_eq_matrix.cc 
    lib/s21_inverse_matrix.cc 
    lib/s21_matrix.cc 
    lib/s21_matrix_overloads.cc 
    lib/s21_matrix_utils.cc 
    lib/s21_mul_matrix.cc 
    lib/s21_mul_number.cc 
    lib/s21_sub_matrix.cc 
    lib/s21_sum_matrix.cc 
    lib/s21_transpose.cc
    s21_matrix_oop.h)

add_executable(
    s21_matrix_tests
    tests/tests_constuctors.cc
    tests/func_for_test.cc
    tests/tests_methods_eqmatrix.cc
    tests/tests_methods_summatrix.cc
    tests/tests_methods_submatrix.cc
    tests/tests_methods_multnumber.cc
    tests/tests_methods_multmatrix.cc
    tests/tests_methods_transpose.cc
    tests/tests_determinant.cc
    tests/tests_calccomplements.cc
    tests/tests_operators_plus.cc
    tests/tests_operators_minus.cc
    tests/tests_operators_mul.cc
    tests/tests_operators_eq.cc
    tests/tests_methods_inversematrix.cc
    tests/tests_methods_get_set.cc
    tests/tests.h
)

target_link_libraries(
    s21_matrix_tests
    s21_matrix_oop
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(s21_matrix_tests)