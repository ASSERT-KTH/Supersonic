#include <stdio.h>

int main() {
  int Q, N, tmp, max, S;
  scanf("%d", &Q);
  bool table[1000001];
  for (int loop = 0; loop < Q; ++loop) {
    memset(table, false, sizeof(table));
    scanf("%d", &N);
    table[N] = true;
    while (N / 10 != 0) {
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (table[N] == true) {
        printf("-1\n");
        break;
      } else {
        table[N] = true;
      }
    }
    if (N / 10 == 0) {
      printf("%d\n", table[N] ? -1 : 0);
    }
  }
  return 0;
}