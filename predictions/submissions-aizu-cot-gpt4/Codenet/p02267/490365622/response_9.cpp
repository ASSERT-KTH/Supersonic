#include <stdio.h>
#include <algorithm>

int main() {
  int n, S[10000], q, i, j, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  std::sort(S, S + n); // Sort the array S
  int T;
  scanf("%d", &q);
  for (j = 0; j < q; j++) {
    scanf("%d", &T);
    if (std::binary_search(S, S + n, T)) // Use binary search to find T in S
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}