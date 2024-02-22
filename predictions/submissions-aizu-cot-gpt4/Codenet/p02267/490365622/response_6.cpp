#include <stdio.h>
#include <algorithm>

int main() {
  int n, S[10000], q, T[500], i, j, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  std::sort(S, S+n);
  for (i = 0; i < q; i++)
    if (std::binary_search(S, S+n, T[i]))
      cnt++;
  printf("%d\n", cnt);
  return 0;
}