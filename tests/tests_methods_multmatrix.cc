#include "tests.h"

TEST(S21MatrixTest, MulMatrixTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 5;
  b(0, 1) = 6;
  b(1, 0) = 7;
  b(1, 1) = 8;

  expected(0, 0) = 19;
  expected(0, 1) = 22;
  expected(1, 0) = 43;
  expected(1, 1) = 50;

  a.MulMatrix(b);

  EXPECT_TRUE(a == expected);
}

TEST(S21MatrixTest, MulNumberTest) {
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;

  a.MulNumber(2);

  EXPECT_TRUE(a == expected);
}

// TEST(tests_methods_mult_matrix, correct_arg_4) {
//   S21Matrix matrix_1(3, 3, {3, 27, 18, 0, 18, 15, 24, 9, 9});
//   S21Matrix matrix_2(3, 3, {3, 18, 24, 21, 15, 24, 0, 27, 3});
//   S21Matrix result(3, 3, {576, 945, 774, 378, 675, 477, 261, 810, 819});
//   matrix_1.MulMatrix(matrix_2);
//   EXPECT_TRUE(matrix_1.EqMatrix(result));
//   EXPECT_TRUE(result.EqMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, correct_arg_5) {
//   S21Matrix matrix_1;
//   S21Matrix matrix_2;
//   S21Matrix result;
//   matrix_1.Assign(-1);
//   matrix_2.Assign(2);
//   result.Assign(-2);
//   matrix_1.MulMatrix(matrix_2);
//   EXPECT_TRUE(matrix_1.EqMatrix(result));
//   EXPECT_TRUE(result.EqMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, correct_arg_6) {
//   S21Matrix matrix_1(3, 2, {0, 1, 3, 4, 6, 7});
//   S21Matrix matrix_2(2, 3, {9, 8, 7, 6, 5, 4});
//   S21Matrix result(3, 3, {6, 5, 4, 51, 44, 37, 96, 83, 70});
//   matrix_1.MulMatrix(matrix_2);
//   EXPECT_TRUE(matrix_1.EqMatrix(result));
//   EXPECT_TRUE(result.EqMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, correct_arg_7) {
//   S21Matrix matrix_1(3, 2, {0, 1, 3, 4, 6, 7});
//   S21Matrix matrix_2(2, 4, {9, 8, 7, 7, 6, 5, 4, 7});
//   S21Matrix result(3, 4, {6, 5, 4, 7, 51, 44, 37, 49, 96, 83, 70, 91});
//   matrix_1.MulMatrix(matrix_2);
//   EXPECT_TRUE(matrix_1.EqMatrix(result));
//   EXPECT_TRUE(result.EqMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, correct_arg_8) {
//   S21Matrix matrix_1;
//   S21Matrix matrix_2;
//   S21Matrix result;
//   matrix_1.MulMatrix(matrix_2);
//   EXPECT_TRUE(matrix_1.EqMatrix(result));
//   EXPECT_TRUE(result.EqMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, uncorrect_arg) {
//   S21Matrix matrix_1;
//   S21Matrix matrix_2(3, 4);
//   EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
//   EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, uncorrect_arg_2) {
//   S21Matrix matrix_1(rand() % 1000 + 1, rand() % 1000 + 1);
//   S21Matrix matrix_2(rand() % 1000 + 1, rand() % 1000 + 1);
//   EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
//   EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
// }

// TEST(tests_methods_mult_matrix, uncorrect_arg_3) {
//   S21Matrix matrix_1(5, 5);
//   S21Matrix matrix_2(6, 6);
//   EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
//   EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
// }