#include <algorithm>
#include <cstdio>
#include <vector>

static void print_partition_ints(const std::vector<int>& as, const size_t q, const size_t n) {
  auto out_sep = "";
  for (size_t i = 0; i < n; ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::printf(format, out_sep, as[i]);
    out_sep = " ";
  }
  std::printf("\n");
}

static size_t partition(std::vector<int>& as, const size_t first, const size_t last) {
  size_t less = first;
  for (size_t i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      std::swap(as[less], as[i]);
      ++less;
    }
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  size_t n;
  std::scanf("%zu", &n);
  std::vector<int> as(n);
  for (size_t i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}