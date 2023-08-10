#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::SumMatrix(const S21Matrix& other) {
  ValidateMatrix();
  other.ValidateMatrix();
  DimensionCompare(other);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
  return *this;
}
