/**
 * set_roll_a_die.cc
 * Purpose: Trying a program from page 124 of the CS106L course reader
 * 
 * @author Rahul W
 * @version 0.1 11/04/19
 */

#include <cstdlib>
#include <set>
#include <iostream>

const size_t kNumIterations = 10000;

int DieRoll() {
  /* 
   * rand() % 6 gives back a value between 0 and 5, inclusive. Adding one to
   * this gives us a valid number for a die roll.
   */
  return (rand() % 6 ) + 1;
}


/**
 * @brief  Rolls the dice until a number appears twice, then reports the number
 * of die rolls
 */
size_t RunProcess() {
  std::set<int> generated;

  while(true) {
    int nextValue = DieRoll();

    /* check if this value has been rolls before */
    if (generated.count(nextValue)) return generated.size();

    /* otherwise, add this value to the set */
    generated.insert(nextValue);
  }
}


int main() {
  srand(static_cast<unsigned>(time(NULL)));
  size_t total = 0;

  for (size_t k = 0; k < kNumIterations; k++)
    total += RunProcess();
  
  std::cout << "Average number of steps: " << double(total) / kNumIterations;
  std::cout << std::endl;
}