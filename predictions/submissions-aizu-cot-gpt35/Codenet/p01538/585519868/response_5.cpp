#include <stdio.h>
#include <vector>

int main() {
  int Q;
  scanf("%d", &Q);

  std::vector<bool> table(1000001);

  for (int loop = 0; loop < Q; ++loop) {
    int N;
    scanf("%d", &N);

    table.assign(1000001, false);
    table[N] = true;

    int count = 0;
    bool FLG = false;

    while (true) {
      if (N / 10 == 0)
        break;

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