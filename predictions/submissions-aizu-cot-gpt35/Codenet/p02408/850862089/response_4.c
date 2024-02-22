#include <stdio.h>

int main(void) {
  int Cards[4][14] = {0};
  int i, j, n, Num;
  char Mark[2];

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf("%s %d", Mark, &Num);
    if (Mark[0] == 'S') {
      Cards[0][Num - 1] = 1;
    } else if (Mark[0] == 'H') {
      Cards[1][Num - 1] = 1;
    } else if (Mark[0] == 'C') {
      Cards[2][Num - 1] = 1;
    } else if (Mark[0] == 'D') {
      Cards[3][Num - 1] = 1;
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        printf("%c %d\n", "SHCD"[i], j + 1);
      }
    }
  }

  return 0;
}