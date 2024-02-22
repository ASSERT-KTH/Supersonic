#include <stdio.h>

int main(void) {
  int Cards[52] = {0};
  int n, Num;
  char Mark;

  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c%d", &Mark, &Num);
    int index;
    if (Mark == 'S') {
      index = Num - 1;
    } else if (Mark == 'H') {
      index = 13 + Num - 1;
    } else if (Mark == 'C') {
      index = 26 + Num - 1;
    } else if (Mark == 'D') {
      index = 39 + Num - 1;
    }
    Cards[index] = 1;
  }

  for (int j = 0; j < 52; j++) {
    if (Cards[j] != 1) {
      if (j < 13) {
        printf("S %d\n", j + 1);
      } else if (j < 26) {
        printf("H %d\n", j - 12);
      } else if (j < 39) {
        printf("C %d\n", j - 25);
      } else {
        printf("D %d\n", j - 38);
      }
    }
  }

  return 0;
}