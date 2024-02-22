#include <algorithm>
#include <iostream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q) {
  auto out_sep = "";
  for (auto i = 0u; i < as.size(); ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::cout << out_sep << (i != q ? as[i] : "[" + std::to_string(as[i]) + "]");
    out_sep = " ";
  }
  std::cout << "\n";
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  int pivot = as[last];
  uint less = first;
  uint more = last;
  while (true) {
    while (as[less] < pivot && less < more) less++;
    while (as[more] >= pivot && more > less) more--;
    if (less >= more) break;
    std::swap(as[less], as[more]);
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q);
}