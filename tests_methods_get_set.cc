#include "tests.h"

TEST(tests_methods_set, correct_arg) {
  S21Matrix matrix(5, 3);
  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 3);
  matrix.SetRows(24);
  EXPECT_EQ(matrix.GetRows(), 24);
  EXPECT_EQ(matrix.GetCols(), 3);
  matrix.SetCols(56);
  EXPECT_EQ(matrix.GetRows(), 24);
  EXPECT_EQ(matrix.GetCols(), 56);
  matrix.SetRows(1);
  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 56);
  matrix.SetCols(2);
  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 2);
  EXPECT_ANY_THROW(matrix.SetRows(0));
  EXPECT_ANY_THROW(matrix.SetCols(0));
  EXPECT_ANY_THROW(matrix.SetRows(-5));
  EXPECT_ANY_THROW(matrix.SetCols(-6));
}

TEST(tests_methods_get, def) {
  S21Matrix matrix(4, 7);
  EXPECT_EQ(matrix.GetCols(), 7);
  EXPECT_EQ(matrix.GetRows(), 4);
}