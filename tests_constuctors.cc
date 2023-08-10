#include "tests.h"

TEST(tests_constuctors, not_argument) {
  S21Matrix matrix;
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 5);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
}

TEST(tests_constuctors, correct_arg_1) {
  S21Matrix matrix(5, 25);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 25);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, simple_argument_2) {
  S21Matrix matrix(12, 12);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 12);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 12);
  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, simple_argument_3) {
  S21Matrix matrix(3, 4);
  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 4);
  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, simple_argument_4) {
  S21Matrix other(1000, 1500);
  EXPECT_EQ(other.GetRows(), 1000);
  EXPECT_EQ(other.GetCols(), 1500);
  S21Matrix matrix(other);
  CheckMatrix(0, matrix);
  CheckMatrix(0, other);
  EXPECT_EQ(matrix.GetRows(), 1000);
  EXPECT_EQ(matrix.GetCols(), 1500);
  EXPECT_TRUE(matrix.EqMatrix(other));
  EXPECT_TRUE(other.EqMatrix(matrix));
}

TEST(tests_constuctors, old_test_1) {
  S21Matrix matrix(100, 100);
  EXPECT_EQ(matrix.GetRows(), 100);
  EXPECT_EQ(matrix.GetCols(), 100);
  CheckMatrix(0, matrix);
}

TEST(tests_constuctors, uncorrect_argument) {
  EXPECT_ANY_THROW(S21Matrix matrix(-5, 25));
  EXPECT_ANY_THROW(S21Matrix matrix(-23, -25));
  EXPECT_ANY_THROW(S21Matrix matrix(-24, -234234));
}

TEST(tests_constuctors, uncorrect_argument_2) {
  EXPECT_THROW(S21Matrix matrix(-1, 2), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(2, -1), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(0, -4), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(-4, 0), std::invalid_argument);
}

TEST(tests_constuctors, copy_constructor) {
  S21Matrix other(5, 6);
  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 5);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 6);
  CheckMatrix(0, matrix);
  EXPECT_TRUE(matrix.EqMatrix(other));
  EXPECT_TRUE(other.EqMatrix(matrix));
}

TEST(tests_constuctors, copy_constructor_2) {
  S21Matrix other(3, 3);
  int num = 1;
  for (int i = 0; i < other.GetRows(); i++) {
    for (int j = 0; j < other.GetCols(); j++) {
      other(i, j) = num++;
    }
  }
  S21Matrix matrix(other);
  EXPECT_DOUBLE_EQ(matrix.GetRows(), 3);
  EXPECT_DOUBLE_EQ(matrix.GetCols(), 3);
  EXPECT_TRUE(matrix.EqMatrix(other));
  EXPECT_TRUE(other.EqMatrix(matrix));
}

TEST(tests_constuctors, copy_constructor_3) {
  S21Matrix matrix1(2, 2);
  int num = 1;
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1(i, j) = num++;
    }
  }
  S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_TRUE(matrix2.EqMatrix(matrix1));
  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      EXPECT_EQ(matrix2(i, j), matrix1(i, j));
    }
  }
}

TEST(tests_constuctors, move_constructor) {
  S21Matrix matrix1(2, 2);

  int num = 1;
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1(i, j) = num++;
    }
  }

  S21Matrix matrix2(matrix1);
  S21Matrix matrix3(std::move(matrix1));
  EXPECT_EQ(matrix3.GetRows(), 2);
  EXPECT_EQ(matrix3.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 0);
  EXPECT_EQ(matrix1.GetCols(), 0);
  EXPECT_TRUE(matrix3.EqMatrix(matrix2));
  for (int i = 0; i < matrix3.GetRows(); i++) {
    for (int j = 0; j < matrix3.GetCols(); j++) {
      EXPECT_EQ(matrix3(i, j), matrix2(i, j));
    }
  }
}
