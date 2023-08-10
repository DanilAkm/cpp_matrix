#include "tests.h"

TEST(tests_methods_sub_matrix, correct_arg) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  S21Matrix result(3, 3);

  for (int i = 0; i < matrix_1.GetRows(); i++) {
    for (int j = 0; j < matrix_1.GetCols(); j++) {
      matrix_1(i, j) = 7;
    }
  }

  for (int i = 0; i < matrix_2.GetRows(); i++) {
    for (int j = 0; j < matrix_2.GetCols(); j++) {
      matrix_2(i, j) = 5;
    }
  }

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      result(i, j) = 2;
    }
  }

  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_sub_matrix, correct_arg_3) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);
  S21Matrix result(1, 1);
  matrix_1(0, 0) = 1.25;
  matrix_2(0, 0) = 2.25;
  result(0, 0) = -1;
  matrix_1.SubMatrix(matrix_2);
  EXPECT_TRUE(matrix_1.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix_1));
}

TEST(tests_methods_sub_matrix, uncorrect_arg_2) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST(tests_methods_sub_matrix, uncorrect_arg_3) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);
  EXPECT_ANY_THROW(matrix1.SetCols(0));
  EXPECT_ANY_THROW(matrix1.SetRows(0));
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}
