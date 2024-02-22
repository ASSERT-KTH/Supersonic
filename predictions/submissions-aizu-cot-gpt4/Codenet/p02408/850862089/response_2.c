#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark;
  char suits[] = {'S', 'H', 'C', 'D'};

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %c", &Mark);
    scanf("%d", &Num);
    if (Mark == 'S') {
      Cards[0][Num - 1] = 1;
    } else if (Mark == 'H') {
      Cards[1][Num - 1] = 1;
    } else if (Mark == 'C') {
      Cards[2][Num - 1] = 1;
    } else if (Mark == 'D') {
      Cards[3][Num - 1] = 1;
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 1; j < 14; j++) {
      if (Cards[i][j - 1] != 1) {
        printf("%c %d\n", suits[i], j);
      }
    }
  }

  return 0;
}