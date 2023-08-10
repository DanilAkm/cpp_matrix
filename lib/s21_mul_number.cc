#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::MulNumber(const double num) {
  ValidateMatrix();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
  return *this;
}
