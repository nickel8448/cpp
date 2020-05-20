/*
 * Problem: https://codeforces.com/problemset/problem/1294/A
 * Status: Worked. Edge case was to check if that no sister has more than
 * totalcoins / 3
 */

#include <iostream>
#include <vector>

int main() {
  int num_test_cases;
  std::cin >> num_test_cases;
  for (int i = 0; i < num_test_cases; i++) {
    int a, b, c, n;
    std::cin >> a >> b >> c >> n;
    int totalCoins = a + b + c + n;
    if (totalCoins % 3 == 0 && a <= totalCoins / 3 && b <= totalCoins / 3 &&
        c <= totalCoins / 3)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
