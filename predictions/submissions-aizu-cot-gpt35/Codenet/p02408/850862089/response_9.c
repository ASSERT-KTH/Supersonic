#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{0}};
  int i, j, n, Num;
  char Mark;
  char marks[] = {'S', 'H', 'C', 'D'};

  scanf("%d", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c%d", &Mark, &Num);
    for (j = 0; j < 4; j++) {
      if (Mark == marks[j]) {
        Cards[j][Num - 1] = 1;
        break;
      }
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        printf("%c %d\n", marks[i], j + 1);
      }
    }
  }

  return 0;
}