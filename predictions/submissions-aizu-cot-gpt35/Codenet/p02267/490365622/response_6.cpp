#include <stdio.h>
#include <stdbool.h>

int main() {
  int n, q, i, cnt = 0;
  bool S[10000] = {false};
  int T[500];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int element;
    scanf("%d", &element);
    S[element] = true;
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  for (i = 0; i < q; i++) {
    if (S[T[i]]) {
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}