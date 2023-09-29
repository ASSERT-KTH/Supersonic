#include <algorithm>
#include <cstdio>
int main() {
  int n, i, f;
  scanf("%d", &n);
  int* A = new int[n];
  for (i = 0; i < n; i++)
    scanf("%d", A + i);
  std::sort(A, A + n);
  for (i = f = 0; i < n; i++)
    printf(f ? " %d" : "%d", A[i]), f = 1;
  delete [] A;
  return 0;
}