#include <stdio.h>

int main() {
  int cSize;
  scanf("%d%*d", &cSize);

  int c[cSize];
  for (int i = 0; i < cSize; i++) {
    scanf("%d", &c[i]);
  }

  int x;
  while (scanf("%d", &x) != EOF) {
    int m = x + 1;
    for (int i = 0; i < cSize; i++) {
      int numCoins = x - c[i] >= 0 ? d[x - c[i]] + 1 : m;
      if (numCoins < m) {
        m = numCoins;
      }
    }
    d[x] = m;
  }

  printf("%d\n", d[x]);

  return 0;
}