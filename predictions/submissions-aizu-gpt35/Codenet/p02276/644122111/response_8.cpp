#include <algorithm>
#include <cstdio>
using uint = unsigned int;
static void print_partition_ints(const int as[], const uint q, const uint n) {
  char out_sep = '\0';
  for (uint i = 0; i < n; ++i) {
    char format[5] = {'\0'};
    if (i != q) {
      format[0] = out_sep;
      format[1] = '%';
      format[2] = 'd';
    } else {
      format[0] = out_sep;
      format[1] = '[';
      format[2] = '%';
      format[3] = 'd';
      format[4] = ']';
    }
    std::printf(format, as[i]);
    out_sep = ' ';
  }
  std::printf("\n");
}
static uint partition(int as[], const uint first, const uint last) {
  uint less = first;
  for (uint i = first; i < last; ++i) {
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
  std::scanf("%u", &n);
  int *as = new int[n];
  for (uint i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  delete[] as;
}