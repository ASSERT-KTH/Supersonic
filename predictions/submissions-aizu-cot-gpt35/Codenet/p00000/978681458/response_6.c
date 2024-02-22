#include <stdio.h>

int main(void) {
  int k;
  int results[81]; // 9x9 matrix

  for (k = 1; k <= 81; k++) {
    int i = (k - 1) / 9 + 1;
    int j = (k - 1) % 9 + 1;
    results[k - 1] = i * j;
  }

  for (k = 0; k < 81; k++) {
    int i = k / 9 + 1;
    int j = k % 9 + 1;
    printf("%dx%d=%d\n", i, j, results[k]);
  }

  return 0;
}