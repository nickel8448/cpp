/**
 * matrix_multiplication.cc
 * Purpose: Implementing different ways of multiplying matricies
 *
 * @author Rahul W
 * @version 0.1 01/06/20
 *
 */
#include <vector>

using std::vector;
using matrix = vector<vector<int>>;

matrix MultiplyMatrix(const matrix &matrixOne, const matrix &matrixTwo) {
  // TODO: Check if the matrix can be multiplied or by putting the
  // 1. Create an output matrix with the right output size
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

void PrintMatrix(const matrix &m);

int main(int argc, char const *argv[]) {
  matrix matrixOne;
  return 0;
}
