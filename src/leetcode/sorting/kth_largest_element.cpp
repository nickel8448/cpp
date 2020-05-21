#include <iostream>
#include <vector>

using std::vector;

int kthLargest(vector<int>& nums, int low, int high, int k);
int partition(vector<int>& nums, int low, int high);

int findKthLargest(const vector<int>& nums, int k) {
  vector<int> working_vector(nums);
  if ((unsigned long)k > nums.size() - 1) {
    return -1;
  } else {
    return kthLargest(working_vector, 0, working_vector.size() - 1, working_vector.size() - k - 1);
  }
}

// Functions find the kthLargest element in an unsorted array
// This function relies on the partition function for the working
int kthLargest(vector<int>& nums, int low, int high, int k) {
  int partition_index = partition(nums, low, high);
  if (partition_index == k) return nums.at(partition_index);
  else if (partition_index > k)
    return kthLargest(nums, low, partition_index - 1, k);
  else
    return kthLargest(nums, partition_index + 1, high, k);
}

int partition(vector<int>& nums, int low, int high) {
  int pivot = nums.at(high), pivot_index = low;
  for (int i = low; i <= high; i++) {
    if (nums.at(i) < pivot) {
      std::swap(nums.at(i), nums.at(pivot_index++));
    }
  }
  std::swap(nums.at(high), nums.at(pivot_index));
  return pivot_index;
}

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  std::cout << findKthLargest(nums, 2) << std::endl;
}
