/**
 * matrix_multiplication.cc
 * Purpose: Implementing different ways of multiplying matricies
 *
 * @author Rahul W
 * @version 0.1 01/06/20
 *
 */
#include <iostream>
#include <vector>

using std::vector;
using matrix = vector<vector<int>>;

matrix MultiplyMatrix(const matrix &matrixOne, const matrix &matrixTwo) {
  // TODO: Check if the matrix can be multiplied or by putting the
  // Number of rows come from the number of rows in matrixOne
  // Number of cols come from the number of cols in matrixTwo
  matrix outputMatrix(matrixOne.size(), vector<int>(matrixTwo.at(0).size()));
  for (size_t i = 0; i < matrixOne.size(); ++i) {
    for (size_t j = 0; j < matrixTwo.at(0).size(); ++j) {
      outputMatrix.at(i).at(j) = 0;
      // Choosing number of rows in matrixOne since we are assuming that
      // the size of the matarices would be n^2
      for (size_t k = 0; k < matrixOne.size(); ++k) {
        outputMatrix.at(i).at(j) +=
            matrixOne.at(i).at(k) * matrixTwo.at(k).at(j);
      }
    }
  }
  return outputMatrix;
}

// Function sums up two matrices of length 1
void SumMatrix(matrix &outputMatrix, const matrix &matrixOne,
               const matrix &matrixTwo, int row, int col) {
  outputMatrix.at(row).at(col) = matrixOne.at(0).at(0) + matrixTwo.at(0).at(0);
}

matrix MultiplyMatrixRecursive(const matrix &matrixOne, const matrix &matrixTwo,
                               int rowA, int rowB, int colA, int colB,
                               int size) {
  matrix outputMatrix(matrixOne.size(), vector<int>(matrixTwo.at(0).size()));
  if (size == 1)
    // TODO: Return the matrix here and remove the else statement
    outputMatrix.at(0).at(0) = matrixOne.at(rowA).at(colA) *
                               matrixTwo.at(rowB).at(colB);
  else {
    int newSize = size / 2;
    matrix A = MultiplyMatrixRecursive(matrixOne, matrixTwo, rowA, rowB, colA,
                                         colB, newSize);
    matrix B = MultiplyMatrixRecursive(matrixOne, matrixTwo, rowA, rowB + newSize, colA + newSize, colB, newSize);
    
    //TODO: Finish the implementation
    // SumMatrix(outputMatrix, A, B, 0, 0);
    // SumMatrix(outputMatrix, , , 0, newSize);
    // SumMatrix(outputMatrix, , , newSize, 0);
    // SumMatrix(outputMatrix, , , newSize, newSize);
  }
  return outputMatrix;
}

void PrintMatrix(const matrix &m) {
  for (size_t i = 0; i < m.size(); ++i) {
    for (size_t j = 0; j < m.at(0).size(); ++j) {
      std::cout << m.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  matrix matrixOne(2, vector<int>(2));
  matrix matrixTwo(2, vector<int>(2));
  int counter = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      matrixOne.at(i).at(j) = counter;
      matrixTwo.at(i).at(j) = counter + 4;
      ++counter;
    }
  }
  PrintMatrix(matrixOne);
  PrintMatrix(matrixTwo);

  matrix outputMatrix = MultiplyMatrix(matrixOne, matrixTwo);
  PrintMatrix(outputMatrix);
  return 0;
}
