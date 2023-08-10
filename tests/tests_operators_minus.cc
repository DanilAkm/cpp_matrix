#include "tests.h"

TEST(SubMatrix, SubNormalAndOverload) {
  S21Matrix test_matrix(2, 2);
  test_matrix(0, 0) = 4;
  test_matrix(0, 1) = 4;
  test_matrix(1, 0) = 4;
  test_matrix(1, 1) = 4;
  S21Matrix other_matrix(2, 2);
  other_matrix(0, 0) = 1;
  other_matrix(0, 1) = 1;
  other_matrix(1, 0) = 1;
  other_matrix(1, 1) = 1;
  test_matrix.SubMatrix(other_matrix);
  for (int i = 0; i < test_matrix.GetRows(); i++) {
    for (int j = 0; j < test_matrix.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(test_matrix(i, j), 3.0);
    }
  }
  S21Matrix overload_result = test_matrix - other_matrix;
  for (int i = 0; i < overload_result.GetRows(); i++) {
    for (int j = 0; j < overload_result.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(overload_result(i, j), 2.0);
    }
  }
  overload_result -= other_matrix;
  for (int i = 0; i < overload_result.GetRows(); i++) {
    for (int j = 0; j < overload_result.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(overload_result(i, j), 1.0);
    }
  }
}
