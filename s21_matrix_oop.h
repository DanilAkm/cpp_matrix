#include <ctype.h>

#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_ = 0;
  int cols_ = 0;
  double** matrix_ = nullptr;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const int rows, const int cols, const std::vector<double>& data);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  // other methods
  bool EqMatrix(const S21Matrix& other) const;

  S21Matrix& SumMatrix(const S21Matrix& other);
  S21Matrix& SubMatrix(const S21Matrix& other);
  S21Matrix& MulNumber(const double num);
  S21Matrix& MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix GetMinorMatrix(const int row, const int col) const;

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);

  friend S21Matrix operator*(const double num, const S21Matrix& matrix);
  friend S21Matrix operator*(const S21Matrix& matrix, const double num);

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& number);

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& matrix) noexcept;

  bool operator==(const S21Matrix& other) const;

  double& operator()(const size_t i, const size_t j);
  double operator()(const size_t i, const size_t j) const;

  int GetRows() const noexcept;
  int GetCols() const noexcept;

  void SetRows(const int rows);
  void SetCols(const int cols);

 private:
  void CreateMatrix();
  void DeleteMatrix(const int counter_allocated_mem);

  void ValidateRowsCols() const;
  void ValidateMatrix() const;
  void ValidateAll() const;

  void DimensionCompare(const S21Matrix& other);
};

S21Matrix operator*(const double num, const S21Matrix& matrix);
S21Matrix operator*(const S21Matrix& matrix, const double num);