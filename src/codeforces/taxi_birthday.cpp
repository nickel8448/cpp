#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  int num_groups = 0;
  const int taxi_max = 4;
  std::cin >> num_groups;
  std::vector<int> num_students;
  for (int i = 0; i < num_groups; ++i) {
    int num;
    std::cin >> num;
    num_students.push_back(num);
  }
  std::sort(num_students.begin(), num_students.end());
  int end_pointer = num_students.size() - 1;
  int start_pointer = 0;
  int num_taxis = 0;
  while (start_pointer != end_pointer) {
    if (num_students.at(end_pointer) + num_students.at(start_pointer) <=
        taxi_max) {
      num_students.at(end_pointer) += num_students.at(start_pointer);
      start_pointer++;
    } else {
      end_pointer--;
      num_taxis++;
    }
  }
  std::printf("%d\n", num_taxis + 1);
}
