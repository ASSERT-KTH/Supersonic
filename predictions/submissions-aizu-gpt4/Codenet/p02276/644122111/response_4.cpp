#include <cstdio>
#define MAX_SIZE 10000
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
  auto pivot = as[last];
  auto i = (first - 1);
  for (uint j = first; j <= last - 1; j++) {
    if (as[j] <= pivot) {
      i++;
      std::swap(as[i], as[j]);
    }
  }
  std::swap(as[i + 1], as[last]);
  return (i + 1);
}

int main() {
  uint n;
  std::scanf("%u", &n);
  int as[MAX_SIZE];
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}