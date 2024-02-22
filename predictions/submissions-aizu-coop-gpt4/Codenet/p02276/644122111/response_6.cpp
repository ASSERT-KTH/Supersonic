#include <algorithm>
#include <iostream>
#include <vector>

using uint = unsigned int;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  for (auto i = 0u; i < n; ++i) {
    if (i == q) std::cout << "[" << as[i] << "]" << " ";
    else std::cout << as[i] << " ";
  }
  std::cout << "\n";
}

uint partition(std::vector<int>& as, const uint first, const uint last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      swap(as[less], as[i]);
      ++less;
    }
  }
  swap(as[less], as[last]);
  return less;
}

int main() {
  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}