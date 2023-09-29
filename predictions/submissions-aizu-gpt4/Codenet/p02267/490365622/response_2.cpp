#include <stdio.h>
#include <algorithm>

int main() {
  int n, S[10000], q, T[500], i, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);

  std::sort(S, S + n);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if(std::binary_search(S, S + n, T[i]))
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}