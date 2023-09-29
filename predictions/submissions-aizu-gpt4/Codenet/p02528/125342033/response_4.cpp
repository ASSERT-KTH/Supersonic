#include <cstdio>
#include <algorithm>

#define MAX 1000001

int main() {
  int n, i, A[MAX];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", A + i);
  std::sort(A, A + n);
  printf("%d", A[0]);
  for (i = 1; i < n; i++)
    printf(" %d", A[i]);
  puts("");
  return 0;
}