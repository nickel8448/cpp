#ifndef GRID_CLASS
#define GRID_CLASS

#include <vector>

template <typename T>
class grid {

public:
  // Create an empty grid
  grid();

  // Construct a grid of a specific size
  grid(size_t rows, size_t cols);

  // Empty the grid
  void clear();

  // Resize the grid
  void resize(size_t rows, size_t cols);

  // Returns the number of rows in the grid
  size_t numRows() const;

  // Returns number of cols in the grid
  size_t numCols() const;

  // Returns whether the grid is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Access individual element
  T& getAt(size_t row, size_t col);
  const T& getAt(size_t row, size_t col) const;

  // Defining typedef for iterator
  typedef typename std::vector<T>::iterator iterator;
  typedef typename std::vector<T>::const_iterator const_iterator;

  // Defining iterator
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // Row iterators
  iterator row_begin(size_t row);
  const_iterator row_begin(size_t row) const;
  iterator row_end(size_t row);
  const_iterator row_end(size_t row) const;

  // if myGrid[2][4] is being used the actual call is
  // myGrid.operatorp[](2).operator[](4);
  // To make the above code compile, the object returned by the grid's
  // operator[] must itself define an operator[] 
  // Since this temporary object is used to perform a task normally reserved for
  // the grid, it is sometimes known as a proxy object
  class MutableReference {
  public:
    // Grid is a friend of MutableReference so that the grid can call the
    // private constructor necessary to initialize a MutableReference
    friend class grid;
    T& operator[](size_t col);

  private:
    MutableReference(grid* owner, size_t row);

    grid* const owner;
    const size_t row;
  };

  MutableReference operator[](size_t row);

  class ImmutableReference {
  public:
    friend class grid;
    const T& operator[](size_t col) const;

  private:
    ImmutableReference(const grid* owner, size_t row);

    const grid* const owner;
    const size_t row;
  };

  ImmutableReference operator[](size_t row) const;

  bool operator<  (const grid& other) const;
  bool operator<= (const grid& other) const;
  bool operator== (const grid& other) const;
  bool operator!= (const grid& other) const;
  bool operator>= (const grid& other) const;
  bool operator>  (const grid& other) const;

private:
  // The corresponding position in the row-major order representation of
  // the grid is given by index = col + row * ncols

  std::vector<T> elems;
  size_t rows;
  size_t cols;

};

#endif
