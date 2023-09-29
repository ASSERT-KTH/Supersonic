#include <algorithm>
#include <cstdio>
#include <vector>
int main() {
  int n;
  std::vector<int> A;
  scanf("%d", &n);
  A.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);
  std::sort(A.begin(), A.end());
  printf("%d", A[0]);
  for (int i = 1; i < n; i++)
    printf(" %d", A[i]);
  puts("");
  return 0;
}