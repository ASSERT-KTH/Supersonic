#include <cstdio>
#include <iostream>

using uint = unsigned int;

static void print_partition_ints(const int as[], const uint q, const uint n) {
  auto out_sep = "";
  for (auto i = 0u; i < n; ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::printf(format, out_sep, as[i]);
    out_sep = " ";
  }
  std::printf("\n");
}

static uint partition(int as[], const uint first, const uint last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      // std::swap(as[less], as[i]);
      int temp = as[less];
      as[less] = as[i];
      as[i] = temp;
      ++less;
    }
  }
  // std::swap(as[less], as[last]);
  int temp = as[less];
  as[less] = as[last];
  as[last] = temp;
  return less;
}

int main() {
  uint n;
  std::cin >> n;
  int as[n];
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  // print_partition_ints(as, q, n);
  for (auto i = 0u; i < n; ++i) {
    std::cout << as[i] << (i != q ? " " : " [") << (i == q ? "]" : "");
  }
  std::cout << std::endl;
}