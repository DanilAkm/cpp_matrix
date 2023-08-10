#include "../s21_matrix_oop.h"

void S21Matrix::DimensionCompare(const S21Matrix& other) {
  if (this->cols_ != other.cols_ || this->rows_ != other.rows_) {
    throw std::invalid_argument("Different matrix dimensions");
  }
}

void S21Matrix::CreateMatrix() {
  int counter_allocated_mem = 0;
  try {
    matrix_ = new double*[rows_];
    for (; counter_allocated_mem < rows_; ++counter_allocated_mem) {
      matrix_[counter_allocated_mem] = new double[cols_]{0};
    }
  } catch (const std::exception& exc) {
    DeleteMatrix(counter_allocated_mem);
    throw;
  }
}

void S21Matrix::DeleteMatrix(const int counter_allocated_mem) {
  if (matrix_) {
    for (int counter_deallocated_mem = 0;
         counter_deallocated_mem < counter_allocated_mem;
         ++counter_deallocated_mem) {
      if (matrix_[counter_deallocated_mem]) {
        delete[] matrix_[counter_deallocated_mem];
        matrix_[counter_deallocated_mem] = nullptr;
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

int S21Matrix::GetRows() const noexcept { return rows_; }
int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(const int rows) {
  if (rows < 1) {
    throw std::invalid_argument("Rows value must > 0");
  }
  S21Matrix temp(rows, cols_);
  for (int i = 0; i < (rows_ < rows ? rows_ : rows); i++) {
    for (int j = 0; j < temp.cols_; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}

void S21Matrix::SetCols(const int cols) {
  if (cols < 1) {
    throw std::invalid_argument("Cols value must > 0");
  }
  S21Matrix temp(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < (cols_ < cols ? cols_ : cols); j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}

void S21Matrix::ValidateRowsCols() const {
  if (rows_ < 0 || cols_ < 0) {
    throw std::invalid_argument("Index incorrect");
  }
}

void S21Matrix::ValidateMatrix() const {
  if (!matrix_) {
    throw std::invalid_argument("matrix_ == nullptr");
  }
}

void S21Matrix::ValidateAll() const {
  ValidateRowsCols();
  ValidateMatrix();
}

S21Matrix S21Matrix::GetMinorMatrix(const int row, const int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Incorect row or col");
  }
  S21Matrix result(rows_ - 1, cols_ - 1);
  int counter_minor_rows = 0;
  int counter_minor_columns = 0;
  for (int counter_rows = 0; counter_rows < rows_; ++counter_rows) {
    for (int counter_cols = 0; counter_cols < cols_; ++counter_cols) {
      if (counter_rows != row && counter_cols != col) {
        result(counter_minor_rows, counter_minor_columns) =
            (*this)(counter_rows, counter_cols);
        ++counter_minor_columns;
        if (counter_minor_columns == result.cols_) {
          counter_minor_columns = 0;
          ++counter_minor_rows;
        }
      }
    }
  }
  return result;
}
