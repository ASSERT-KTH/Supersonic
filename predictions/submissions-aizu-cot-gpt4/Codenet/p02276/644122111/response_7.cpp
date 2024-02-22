#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q) {
  std::stringstream ss;
  for (uint i = 0; i < as.size(); ++i) {
    if (i != 0) {
      ss << ' ';
    }
    if (i == q) {
      ss << '[' << as[i] << ']';
    } else {
      ss << as[i];
    }
  }
  ss << '\n';
  std::cout << ss.str();
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  uint less = first;
  for (uint i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      std::swap(as[less], as[i]);
      ++less;
    }
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  for (uint i = 0; i < n; ++i) {
    std::cin >> as[i];
  }
  uint q = partition(as, 0, n - 1);
  print_partition_ints(as, q);
  return 0;
}