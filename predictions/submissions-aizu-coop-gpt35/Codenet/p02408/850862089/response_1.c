#include <stdio.h>
#include <stdbool.h>

int main(void) {
  bool Cards[4 * 14]; // 1D array of booleans

  int i, j, n, Num;
  char Mark;

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &Mark, &Num);

    if (Mark == 'S') {
      Cards[0 * 14 + Num - 1] = true;
    } else if (Mark == 'H') {
      Cards[1 * 14 + Num - 1] = true;
    } else if (Mark == 'C') {
      Cards[2 * 14 + Num - 1] = true;
    } else if (Mark == 'D') {
      Cards[3 * 14 + Num - 1] = true;
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 14; j++) {
      if (!Cards[i * 14 + j]) {
        if (i == 0) {
          printf("S ");
        } else if (i == 1) {
          printf("H ");
        } else if (i == 2) {
          printf("C ");
        } else if (i == 3) {
          printf("D ");
        }
        printf("%d\n", j + 1);
      }
    }
  }

  return 0;
}