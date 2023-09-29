#include <cstdio>
using uint = unsigned int;
static void print_partition_ints(const int as[], const uint q, const uint n) {
  char out_sep = '\0';
  for (uint i = 0; i < n; ++i) {
    char format[6] = {};
    sprintf(format, "%s%d", out_sep ? " " : "", as[i]);
    printf("%s", format);
    out_sep = ' ';
  }
  printf("\n");
}
static uint partition(int as[], const uint first, const uint last) {
  const int pivot = as[last];
  uint less = first;
  for (uint i = first; i < last; ++i) {
    if (as[i] <= pivot) {
      std::swap(as[less++], as[i]);
    }
  }
  std::swap(as[less], as[last]);
  return less;
}
int main() {
  uint n;
  std::scanf("%u", &n);
  int* const as = new int[n];
  for (uint i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  const uint q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  delete[] as;
}