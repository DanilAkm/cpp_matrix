#include "tests.h"

TEST(tests_methods_mult_matrix_number, correct_arg) {
  S21Matrix matrix(5, 3);
  S21Matrix result(5, 3);

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = 7;
    }
  }

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      result(i, j) = 28;
    }
  }

  matrix.MulNumber(4);
  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}

TEST(tests_methods_mult_matrix_number, correct_arg_2) {
  int rows = rand() % 1000 + 1;
  int columns = rand() % 1000 + 1;
  double value2 = rand() / rand() + 1;
  S21Matrix matrix(rows, columns);
  S21Matrix result(rows, columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value1 = rand() / rand() + 1;
      matrix(i, j) = value1;
      result(i, j) = value1 * value2;
    }
  }
  matrix.MulNumber(value2);
  EXPECT_TRUE(matrix.EqMatrix(result));
  EXPECT_TRUE(result.EqMatrix(matrix));
}
