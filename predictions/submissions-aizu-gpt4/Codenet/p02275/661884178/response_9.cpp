#include <cstdio>
#include <algorithm>
#define r(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  scanf("%d", &n);
  int min = 2000000, t, A[10001]{};
  r(i, n) {
    scanf("%d", &t);
    min = std::min(min, t);
    ++A[t];
  }
  --A[min];
  printf("%d", min);
  for (int i = min; i < 10001; ++i) {
    r(j, A[i]) { printf(" %d", i); }
  }
  printf("\n");
  return 0;
}