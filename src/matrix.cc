/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <matrix.h>

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}

