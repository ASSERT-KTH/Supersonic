#include <iostream>
#include <vector>

static void print_partition_ints(const std::vector<int>& as, const uint q) {
  auto out_sep = "";
  for (const auto& num : as) {
    auto format = (num != as[q] ? "%s%d" : "%s[%d]");
    std::cout << out_sep << format << num;
    out_sep = " ";
  }
  std::cout << "\n";
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
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q);
}