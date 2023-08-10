#include "tests.h"

TEST(tests_methods_transpose, correct_arg) {
  S21Matrix matrix_1;
  S21Matrix answer;
  S21Matrix result = matrix_1.Transpose();
  EXPECT_TRUE(result.EqMatrix(answer));
  EXPECT_TRUE(answer.EqMatrix(result));
}
