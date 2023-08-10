#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::MulMatrix(const S21Matrix& other) {
  ValidateMatrix();
  other.ValidateMatrix();
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the "
        "number of rows of the second matrix");
  }
  S21Matrix tempMatrix(cols_, other.rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        tempMatrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  DeleteMatrix(rows_);
  *this = std::move(tempMatrix);
  return *this;
}
