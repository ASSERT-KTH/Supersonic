#include <stdio.h>
#include <vector>

int main() {
  int Q;
  scanf("%d", &Q);

  std::vector<bool> table(1000001);
  for (int loop = 0; loop < Q; loop++) {
    table.assign(1000001, false);
    int count = 0;
    int N;
    scanf("%d", &N);
    table[N] = true;
    bool FLG = false;

    while (N >= 10) {
      int max = 0;
      for (int S = 10; N / S != 0; S *= 10) {
        int tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
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