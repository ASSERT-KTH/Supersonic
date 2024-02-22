#include <algorithm>
#include <iostream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  std::string out_sep = "";
  for (uint i = 0; i < n; ++i) {
    const std::string format = (i != q ? "%s%d" : "%s[%d]");
    std::cout << out_sep << as[i];
    out_sep = " ";
  }
  std::cout << "\n";
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
  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  for (uint i = 0; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);

  return 0;
}