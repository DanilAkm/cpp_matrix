#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() const {
  ValidateAll();
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  double determinant = 0.0;
  if (rows_ == 1) {
    return (*this)(0, 0);
  } else if (rows_ == 2) {
    return (*this)(0, 0) * (*this)(1, 1) - ((*this)(0, 1) * (*this)(1, 0));
  } else if (rows_ > 2) {
    int degree = 1;
    for (int counter_columns = 0; counter_columns < cols_; ++counter_columns) {
      S21Matrix rec_matrix = GetMinorMatrix(0, counter_columns);
      double recursion_result = rec_matrix.Determinant();
      determinant += degree * (*this)(0, counter_columns) * recursion_result;
      degree = -degree;
    }
  }
  return determinant;
}
