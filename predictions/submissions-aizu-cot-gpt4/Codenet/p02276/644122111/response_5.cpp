#include <algorithm>
#include <cstdio>
typedef unsigned int uint;

void print_partition_ints(const int as[], const uint q, const uint n) {
  const char* out_sep = "";
  for (uint i = 0; i < n; ++i) {
    const char* format = (i != q ? "%s%d" : "%s[%d]");
    printf(format, out_sep, as[i]);
    out_sep = " ";
  }
  printf("\n");
}

uint partition(int as[], const uint first, const uint last) {
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
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  uint n;
  scanf("%u", &n);

  int* as = (int*)malloc(n * sizeof(int));
  for (uint i = 0; i < n; ++i) {
    scanf("%d", &as[i]);
  }

  uint q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  
  free(as);
  return 0;
}