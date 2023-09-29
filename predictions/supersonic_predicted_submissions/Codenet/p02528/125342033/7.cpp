#include <algorithm>
#include <cstdio>
int main() {
  int n, i, f, A[100010];
  for (scanf("%d", &n), i = 0; i < n; i++)
    scanf("%d", A + i);
  std::sort(A, A + n);
  for (i = f = 0; i < n; i++)
    printf(f ? " %d" : "%d", A[i]), f = 1;
  puts("");
}
