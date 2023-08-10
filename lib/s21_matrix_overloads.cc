#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix operator*(const double num, const S21Matrix& matrix) {
  S21Matrix result(matrix);
  result.MulNumber(num);
  return result;
}
S21Matrix operator*(const S21Matrix& matrix, const double num) {
  S21Matrix result = num * matrix;
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& number) {
  MulNumber(number);
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  ValidateAll();
  other.ValidateAll();
  if (!(other == *this)) {
    SetRows(other.GetRows());
    SetCols(other.GetCols());
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        (*this)(i, j) = other(i, j);
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& matrix) noexcept {
  if (matrix.matrix_ != this->matrix_) {
    if (matrix_ != nullptr) {
      DeleteMatrix(rows_);
    }
    rows_ = matrix.rows_;
    cols_ = matrix.cols_;
    matrix_ = matrix.matrix_;
    matrix.rows_ = 0;
    matrix.cols_ = 0;
    matrix.matrix_ = nullptr;
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& matrix) const {
  return EqMatrix(matrix);
}

double& S21Matrix::operator()(const size_t i, const size_t j) {
  ValidateAll();
  if (static_cast<int>(i) > rows_ - 1 || static_cast<int>(j) > cols_ - 1) {
    throw std::invalid_argument("index is outside the matrix");
  }
  return matrix_[i][j];
}

double S21Matrix::operator()(const size_t i, const size_t j) const {
  ValidateAll();
  if (static_cast<int>(i) > rows_ - 1 || static_cast<int>(j) > cols_ - 1) {
    throw std::invalid_argument("index is outside the matrix");
  }
  return matrix_[i][j];
}
