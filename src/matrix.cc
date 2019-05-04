/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <matrix.h>

template <class T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}

template <class T>
Matrix<T>::~Matrix() {
  for (unsigned int i = 0; i < this->rows_; ++i) {
    delete[] this->m_[i];
  }  // Ending bracket for for loop
  delete[] m_;
}  // Ending bracket for deconstructor

template <class T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
  assert(row < this->rows_);
  assert(col < this->cols_);
  return this->m_[row][col];
}  // Ending bracket for method Get

template <class T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
this->rows_ = rhs.rows_;
this->cols_ = rhs.cols_;

if (this->m_) {
  for (unsigned int i = 0; i < this->rows_; ++i) {
    delete[] this->m_[i];
  }  // Ending bracket for for loop
  delete[] m_;
}  // Ending bracket for if statement

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];
  }  // Ending bracket for for loop;

  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] = rhs.Get(i, j);
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer for loop
return *this;
}  // Ending bracket for method operator=

template <class T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] *= rhs;
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer loop
  return *this;
}  // Ending bracket for method operator*=

template <class T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
  Matrix<T> ret;
  ret.cols_ = cols_;
  ret.rows_ = rows_;

  ret.m_ = new T *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      ret.m_[i] = new T[cols_];
    }  // Ending bracket for for loop


  for (unsigned int i = 0; i < ret.rows_; ++i) {
    for (unsigned int j = 0; j < ret.cols_; ++j) {
      ret.m_[i][j] = ( (this->Get(i, j)) + (rhs.Get(i, j)) );
    }  // Ending bracket for inner for loop
  }  // Ending bracket for outer for loop
  return ret;
}  // Ending bracket for method operator+

template <class T>
unsigned int const Matrix<T>::getRows() const {
  return this->rows_;
}  // Ending bracket for method getRows

template <class T>
unsigned int const Matrix<T>::getCols() const {
  return this->cols_;
}  // Ending bracket for method getRows
