#include <stdio.h>

int main() {
  int n, S[10000], q, T[500], cnt = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);

  for (int i = 0; i < q; i++) {
    scanf("%d", &T[i]);

    for (int j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        cnt++;
        break;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}