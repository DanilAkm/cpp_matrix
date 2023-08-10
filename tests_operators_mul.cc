#include "tests.h"

TEST(Test, operator_mulNumbereq) {
  S21Matrix B(3, 4);
  S21Matrix A(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(0, 3) = 8;
  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 14;
  A(1, 3) = 16;
  A(2, 0) = 18;
  A(2, 1) = 20;
  A(2, 2) = 22;
  A(2, 3) = 24;

  B *= 2;
  EXPECT_EQ(1, B == A);
}
TEST(Test, operator_mulMatrixeq) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B *= A;
  EXPECT_EQ(1, B == expected);
}
TEST(Test, operator_mulMatrix) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B = B * A;
  EXPECT_EQ(1, B == expected);
}
TEST(Test, operator_mulNumber) {
  S21Matrix B(3, 4);
  S21Matrix A(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(0, 3) = 8;
  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 14;
  A(1, 3) = 16;
  A(2, 0) = 18;
  A(2, 1) = 20;
  A(2, 2) = 22;
  A(2, 3) = 24;

  B = 2 * B;
  EXPECT_EQ(1, B == A);
}