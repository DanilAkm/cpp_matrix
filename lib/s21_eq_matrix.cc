#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool result = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    result = false;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > EPS) {
          result = false;
        }
        if (!result) {
          break;
        }
      }
      if (!result) {
        break;
      }
    }
  }
  return result;
}
