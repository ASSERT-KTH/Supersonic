#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  std::ostringstream oss;
  for (auto i = 0u; i < n; ++i) {
    if (i != 0) {
      oss << " ";
    }
    if (i == q) {
      oss << "[" << as[i] << "]";
    } else {
      oss << as[i];
    }
  }
  std::cout << oss.str() << std::endl;
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
  print_partition_ints(as, q, n);
}