#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

// TODO: Club range and count

template<typename ForwardIterator>
void CountingSort(ForwardIterator begin, ForwardIterator end) {
  auto min_max = std::minmax_element(begin, end);
  if(min_max.first == min_max.second)  // empty range
    return;
  auto min = *min_max.first;
  auto max = *min_max.second;
  std::vector<unsigned> count((max - min) + 1, 0u);
  for (auto i = begin; i != end; ++i) {
    ++count[*i - min];
  }
  copy(count.begin(), count.end(), std::ostream_iterator<int>(std::cout, " "));
  // Looping through the range, will loop 399
  for (auto i = min; i <= max; ++i) {
    int numTimesOccured = count[i - min];  // i - min gets the right position
    for (auto j = 0; j < numTimesOccured; ++j) {
      *begin = i;
      begin++;
    }
  }
}


int main() {
  int a[] = {100, 100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
  CountingSort(std::begin(a), std::end(a));
  copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}