#include <algorithm>
#include <stdio.h>

int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  bool table[1000001] = {false};

  for (int loop = 0; loop < Q; ++loop) {
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    FLG = false;

    while (N >= 10) {
      max = 0;
      for (S = 10; N >= S; S *= 10) {
        tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
      }
      N = max;
      if (table[N] == true) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        ++count;
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