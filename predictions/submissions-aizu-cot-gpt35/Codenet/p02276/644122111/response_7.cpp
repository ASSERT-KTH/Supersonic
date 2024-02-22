#include <iostream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  auto out_sep = "";
  for (auto i = 0u; i < n; ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::cout << format << out_sep << as[i];
    out_sep = " ";
  }
  std::cout << std::endl;
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  auto pivot = as[last];
  auto less = std::partition(as.begin() + first, as.begin() + last, [pivot](const int& element) {
    return element <= pivot;
  });
  std::swap(*less, as[last]);
  return std::distance(as.begin(), less);
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