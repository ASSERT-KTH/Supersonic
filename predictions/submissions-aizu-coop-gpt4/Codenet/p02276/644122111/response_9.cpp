#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>
using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  std::ostringstream oss;
  for (auto i = 0u; i < n; ++i) {
    oss << (i != q ? " " : " [") << as[i] << (i != q ? "" : "]");
  }
  std::printf("%s\n", oss.str().c_str());
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      if (i != less) {
        std::swap(as[less], as[i]);
      }
      ++less;
    }
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  std::ios_base::sync_with_stdio(false); // Disable synchronization between C and C++ streams

  uint n;
  std::scanf("%u", &n);
  std::vector<int> as(n);
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}