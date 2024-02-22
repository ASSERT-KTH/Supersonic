#include <cstdio>

using uint = unsigned int;

static void print_partition_ints(const int as[], const uint q, const uint n) {
  for (auto i = 0u; i < n; ++i) {
    if (i != q) {
      std::printf("%d ", as[i]);
    } else {
      std::printf("[%d] ", as[i]);
    }
  }
  std::printf("\n");
}

static uint partition(int as[], const uint first, const uint last) {
  auto pivot = as[last];
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= pivot) {
      std::swap(as[less], as[i]);
      ++less;
    }
  }
  return less - 1;
}

int main() {
  uint n;
  std::scanf("%u", &n);
  int as[n];
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}