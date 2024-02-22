#include <cstdio>
#include <iostream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  std::string out_sep;
  for (auto i = 0u; i < n; ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::printf(format.c_str(), out_sep.c_str(), as[i]);
    out_sep = " ";
  }
  std::printf("\n");
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
  std::scanf("%u", &n);
  std::vector<int> as(n);
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}