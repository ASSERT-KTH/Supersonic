#include <vector>
#include <iostream>
#include <algorithm>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q) {
  for (auto i = 0u; i < q; ++i) {
    std::cout << as[i] << " ";
  }
  std::cout << "[" << as[q] << "] ";
  for (auto i = q + 1; i < as.size(); ++i) {
    std::cout << as[i] << " ";
  }
  std::cout << std::endl;
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      std::swap(as[less], as[i]);
      ++less;
    }
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  for (auto& a : as) {
    std::cin >> a;
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q);
}