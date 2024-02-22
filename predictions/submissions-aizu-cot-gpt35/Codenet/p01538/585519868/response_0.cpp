#include <stdio.h>

int main() {
  int Q, N, count, max, S;
  bool FLG;
  scanf("%d", &Q);
  bool *table = new bool[1000001];

  for (int loop = 0; loop < Q; loop++) {
    std::fill_n(table, 1000001, false);
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    FLG = false;

    while (N >= 10) {
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        int tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
      }
      N = max;
      if (table[N]) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        count++;
      }
    }

    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }

  delete[] table;
  return 0;
}