#include "tests.h"

TEST(complements_matrix, complementsNormal1) {
  S21Matrix test_matrix(3, 3);
  test_matrix(0, 0) = 1.0;
  test_matrix(0, 1) = 2.0;
  test_matrix(0, 2) = 3.0;

  test_matrix(1, 0) = 0.0;
  test_matrix(1, 1) = 4.0;
  test_matrix(1, 2) = 2.0;

  test_matrix(2, 0) = 5.0;
  test_matrix(2, 1) = 2.0;
  test_matrix(2, 2) = 1.0;

  S21Matrix complements_matrix(3, 3);
  complements_matrix(0, 0) = 0.0;
  complements_matrix(0, 1) = 10.0;
  complements_matrix(0, 2) = -20.0;

  complements_matrix(1, 0) = 4.0;
  complements_matrix(1, 1) = -14.0;
  complements_matrix(1, 2) = 8.0;

  complements_matrix(2, 0) = -8.0;
  complements_matrix(2, 1) = -2.0;
  complements_matrix(2, 2) = 4.0;
  S21Matrix other_matrix = test_matrix.CalcComplements();
  EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
}

TEST(complements_matrix, complementsNormal2) {
  S21Matrix test_matrix(3, 3);
  test_matrix(0, 0) = 101.0;
  test_matrix(0, 1) = 2.0;
  test_matrix(0, 2) = -4.0;

  test_matrix(1, 0) = 6.0;
  test_matrix(1, 1) = -3.0;
  test_matrix(1, 2) = 12.0;

  test_matrix(2, 0) = 5.0;
  test_matrix(2, 1) = -2.0;
  test_matrix(2, 2) = 3.0;

  S21Matrix complements_matrix(3, 3);
  complements_matrix(0, 0) = 15.0;
  complements_matrix(0, 1) = 42.0;
  complements_matrix(0, 2) = 3.0;

  complements_matrix(1, 0) = 2.0;
  complements_matrix(1, 1) = 323.0;
  complements_matrix(1, 2) = 212.0;

  complements_matrix(2, 0) = 12.0;
  complements_matrix(2, 1) = -1236.0;
  complements_matrix(2, 2) = -315.0;
  S21Matrix other_matrix = test_matrix.CalcComplements();
  EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
}

// TEST(complements_matrix, complementsBig) {
//   S21Matrix test_matrix(4, 4);
//   test_matrix(0, 0) = 0.023;
//   test_matrix(0, 1) = 124.161;
//   test_matrix(0, 2) = -4.445;
//   test_matrix(0, 3) = 0.123;

//   test_matrix(1, 0) = 6.122;
//   test_matrix(1, 1) = -3.023;
//   test_matrix(1, 2) = 12.011;
//   test_matrix(1, 3) = 4.112;

//   test_matrix(2, 0) = 5.032;
//   test_matrix(2, 1) = -2.120;
//   test_matrix(2, 2) = 3.530;
//   test_matrix(2, 3) = 1.222;

//   test_matrix(3, 0) = 1.032;
//   test_matrix(3, 1) = -3.120;
//   test_matrix(3, 2) = 0.530;
//   test_matrix(3, 3) = 8.34;

//   S21Matrix complements_matrix(4, 4);
//   complements_matrix(0, 0) = 120.198301;
//   complements_matrix(0, 1) = 316.662458;
//   complements_matrix(0, 2) = -17.408659;
//   complements_matrix(0, 3) = 104.696500;

//   complements_matrix(1, 0) = -3514.483058;
//   complements_matrix(1, 1) = 181.479355;
//   complements_matrix(1, 2) = 5056.050798;
//   complements_matrix(1, 3) = 181.469446;

//   complements_matrix(2, 0) = 12116.204486;
//   complements_matrix(2, 1) = -209.216057;
//   complements_matrix(2, 2) = -5814.710587;
//   complements_matrix(2, 3) = -1208.019247;

//   complements_matrix(3, 0) = -44.272415;
//   complements_matrix(3, 1) = -63.492874;
//   complements_matrix(3, 2) = -1640.619098;
//   complements_matrix(3, 3) = 4811.423335;
//   S21Matrix other_matrix = test_matrix.CalcComplements();
//   EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
// }

// TEST(inverseMatrix, inverseNormal) {
//   S21Matrix test_matrix(3, 3);
//   test_matrix(0, 0) = 2.0;
//   test_matrix(0, 1) = 5.0;
//   test_matrix(0, 2) = 7.0;

//   test_matrix(1, 0) = 6.0;
//   test_matrix(1, 1) = 3.0;
//   test_matrix(1, 2) = 4.0;

//   test_matrix(2, 0) = 5.0;
//   test_matrix(2, 1) = -2.0;
//   test_matrix(2, 2) = -3.0;

//   S21Matrix complements_matrix(3, 3);
//   complements_matrix(0, 0) = 1.0;
//   complements_matrix(0, 1) = -1.0;
//   complements_matrix(0, 2) = 1.0;

//   complements_matrix(1, 0) = -38.0;
//   complements_matrix(1, 1) = 41.0;
//   complements_matrix(1, 2) = -34.0;

//   complements_matrix(2, 0) = 27.0;
//   complements_matrix(2, 1) = -29.0;
//   complements_matrix(2, 2) = 24.0;
//   S21Matrix other_matrix = test_matrix.InverseMatrix();
//   EXPECT_EQ(other_matrix.EqMatrix(complements_matrix), true);
//   EXPECT_EQ(test_matrix.EqMatrix(complements_matrix), false);
// }