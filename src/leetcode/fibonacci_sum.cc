/**
 * finonacci_sum.cc
 * Purpose: Sum of fibonacci numbers until x
 * 
 * fibonacci number - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
 * 
 * https://leetcode.com/problems/fibonacci-number/
 *  
 * @author Rahul W
 * @version 0.1 10/20/19
 */

#include <iostream>


int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n-1) + fib(n-2);
}


int main() {
  std::cout << fib(4) << std::endl;
}