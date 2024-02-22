#include <stdio.h>
#include <vector>

int main() {
  int Q, N, count, tmp, max, S;
  scanf("%d", &Q);
  std::vector<bool> table(1000001);
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table.assign(1000001, false);
    table[N] = true;
    while (N >= 10) {
      max = 0;
      for (S = 10; N >= S; S *= 10) {
        tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
      }
      N = max;
      if (table[N]) {
        N = -1;
        break;
      }
      table[N] = true;
      count++;
    }
    if (N == -1) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}