#include <stdio.h>
#include <array>

int main() {
  int Q, N, count, tmp, maxProduct, S;
  bool FLG;
  scanf("%d", &Q);
  std::array<bool, 1000001> table;
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table.fill(false);
    table[N] = true;
    FLG = false;
    while (N != 0) {
      maxProduct = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        maxProduct = (maxProduct >= tmp) ? maxProduct : tmp;
      }
      N = maxProduct;
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