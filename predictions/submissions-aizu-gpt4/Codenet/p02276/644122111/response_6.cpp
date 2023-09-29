#include <cstdio>
typedef unsigned int uint;
inline void print_partition_ints(const int as[], const uint q, const uint n) {
  for (uint i = 0; i < n; ++i) {
    std::printf((i != q ? " %d" : " [%d]"), as[i]);
  }
  std::putchar('\n');
}
inline uint partition(int as[], const uint first, const uint last) {
  auto pivot = as[last];
  uint i = first;
  for (uint j = first; j < last; ++j) {
    if (as[j] < pivot) {
      std::swap(as[i], as[j]);
      ++i;
    }
  }
  std::swap(as[i], as[last]);
  return i;
}
int main() {
  uint n;
  std::scanf("%u", &n);
  int as[n];
  for (uint i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  return 0;
}