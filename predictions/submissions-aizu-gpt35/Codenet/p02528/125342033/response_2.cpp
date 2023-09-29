#include <algorithm>
#include <cstdio>
int main() {
  int n, i, f, A[1000001];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
  std::sort(A, A + n);
  for (i = f = 0; i < n; i++)
    printf(f ? " %d" : "%d", A[i]), f = 1;
  puts("");
}