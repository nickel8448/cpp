/*
 * =====================================================================================
 *
 *       Filename:  expression.cpp
 *
 *    Description: https://codeforces.com/problemset/problem/479/A
 *
 *        Version:  1.0
 *        Created:  11/05/2020 22:22:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>

int main() {
  int ans, a, b, c;
  while (std::cin >> a >> b >> c) {
    ans = a + b + c;
    ans = std::max(ans, (a * b * c));
    ans = std::max(ans, (a + b) * c);
    ans = std::max(ans, a + (b * c));
    ans = std::max(ans, a * (b + c));
    ans = std::max(ans, (a * b) + c);
    std::cout << ans << std::endl;
  }
}
