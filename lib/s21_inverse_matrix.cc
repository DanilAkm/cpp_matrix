#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() const {
  ValidateAll();
  double determinant = Determinant();
  if (!determinant) {
    throw std::invalid_argument("Matrix determinant is 0");
  }
  S21Matrix transpose = CalcComplements().Transpose();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      transpose(i, j) = transpose(i, j) / determinant;
    }
  }
  return transpose;
}
