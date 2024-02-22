#include <iostream>
#include <utility>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  bool is_first = true;
  for (auto i = 0u; i < n; ++i) {
    auto format = (i != q ? "%d" : "[%d]");
    if (!is_first) {
      std::cout << " ";
    } else {
      is_first = false;
    }
    std::cout << as[i];
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
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}