#include <cstdio>
#include <algorithm>

#define MAX_SIZE 1000001

int main() {
  int n;
  static int A[MAX_SIZE];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", A + i);
  std::sort(A, A + n);
  printf("%d", A[0]);
  for (int i = 1; i < n; ++i)
    printf(" %d", A[i]);
  puts("");
  return 0;
}