#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long int> counts(100007);
  for(int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    counts.at(num)++;
  }
  std::vector<long long int> dp(100007);
  dp.at(0) = 0;
  dp.at(1) = counts.at(1);
  for(int i = 2; i <= 100000; ++i) {
    dp.at(i) = std::max(dp.at(i - 1), dp.at(i - 2) + i * counts.at(i));
  }
  std::cout << dp.at(100000);
  return 0;
}
