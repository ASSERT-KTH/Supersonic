#include <cstdio>
typedef unsigned int uint;

inline void print_partition_ints(int* as, uint q, uint n) {
  char* out_sep = "";
  for (uint i = 0; i < n; ++i) {
    printf((i != q ? "%s%d" : "%s[%d]"), out_sep, as[i]);
    out_sep = " ";
  }
  printf("\n");
}

inline uint partition(int* as, uint first, uint last) {
  uint less = first;
  for (uint i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      int temp = as[less];
      as[less] = as[i];
      as[i] = temp;
      ++less;
    }
  }
  int temp = as[less];
  as[less] = as[last];
  as[last] = temp;
  return less;
}

int main() {
  uint n;
  scanf("%u", &n);
  int* as = new int[n];
  for (uint i = 0; i < n; ++i) {
    scanf("%d", &as[i]);
  }
  uint q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  delete[] as;
  return 0;
}