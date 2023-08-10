#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  ValidateAll();
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result(0, 0) = 1;
    return result;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result(i, j) =
          GetMinorMatrix(i, j).Determinant() * std::pow(-1, i + 1 + j + 1);
    }
  }
  return result;
}
