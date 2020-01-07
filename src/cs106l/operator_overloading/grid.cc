#include <iostream>
#include <algorithm>

#include "grid.h"

template <typename T>
grid<T>::grid() : rows(0), cols(0) {

}

template <typename T>
grid<T>::grid(size_t rows, size_t cols) :
  elems(rows * cols), rows(rows), cols(cols) {

}

template <typename T>
void grid<T>::clear() {
  resize(0, 0);
}

template <typename T>
void grid<T>::resize(size_t rows, size_t cols) {
  // assign function replaces the contents with the count copies of
  // the value. In this case, the values are being replaced by the elemtype()
  // return
  // TODO: Write about this in anki
  T defaultValue = T();
  elems.assign(rows * cols, defaultValue);

  this->rows = rows;
  this->cols = cols;
}

template <typename T>
size_t grid<T>::numRows() const {
  return this->rows;
}

template <typename T>
size_t grid<T>::numCols() const {
  return this->cols;
}

template <typename T>
bool grid<T>::empty() const {
  return this->size() == 0;
}

template <typename T>
size_t grid<T>::size() const {
  return this->numRows * this->numCols;
}

template <typename T>
T& grid<T>::getAt(size_t row, size_t col) {
  return elems[col + row * cols];
}

template <typename T>
const T& grid<T>::getAt(size_t row, size_t col) const {
  return elems[col + row * cols];
}

template <typename T>
typename grid<T>::iterator grid<T>::begin() {
  return elems.begin();
}

template <typename T>
typename grid<T>::const_iterator grid<T>::begin() const {
  return elems.begin();
}

template <typename T>
typename grid<T>::iterator grid<T>::end() {
  return elems.end();
}

template <typename T>
typename grid<T>::const_iterator grid<T>::end() const {
  return elems.end();
}

template <typename T>
typename grid<T>::iterator grid<T>::row_begin(size_t row) {
  return begin() + numCols() * row;
}

template <typename T>
typename grid<T>::const_iterator grid<T>::row_begin(size_t row) const {
  return begin() + numCols() * row;
}

template <typename T>
typename grid<T>::iterator grid<T>::row_end(size_t row) {
  return row_begin(row) + numCols();
}

template <typename T>
typename grid<T>::const_iterator grid<T>::row_end(size_t row) const {
  return row_begin(row) + numCols();
}

// Default constructor for MutableReference class
template <typename T>
grid<T>::MutableReference::MutableReference(grid* owner, size_t row) :
  owner(owner), row(row) {
}

template <typename T>
T& grid<T>::MutableReference::operator[] (size_t col) {
  // getAt is mutable based on the implementation of the function
  return owner->getAt(row, col);
}

template <typename T>
typename grid<T>::MutableReference grid<T>::operator[](size_t row) {
  return MutableReference(this, row); 
  // MutableReference.operator[row] - This is the call which will be made
  // This function returns a MutableReference
}

template <typename T>
grid<T>::ImmutableReference::ImmutableReference(const grid* owner, size_t row):
  owner(owner), row(row) {
}

template <typename T>
const T& grid<T>::ImmutableReference::operator[](size_t col) const {
  return this->getAt(row, col);
}

template <typename T>
typename grid<T>::ImmutableReference grid<T>::operator[](size_t row) const {
  return ImmutableReference(this, row);  
}

template <typename T>
bool grid<T>::operator< (const grid& other) const {
  // Compare the number of rows and return if there's a mismatch
  if (rows != other.rows)
    return rows < other.rows;

  if (cols != other.cols)
    return cols < other.cols;

  return std::lexicographical_compare(begin(), end(), other.begin(),
      other.end());
}

int main() {
  return 0;
}
