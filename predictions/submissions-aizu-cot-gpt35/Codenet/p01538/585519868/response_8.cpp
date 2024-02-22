#include <stdio.h>
#include <vector>

int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  std::vector<bool> table(1000001, false);
  for (int loop = 0; loop < Q; loop++) {
    table.assign(1000001, false);
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    FLG = false;
    while (true) {
      if (N < 10)
        break;
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
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
  return 0;
}