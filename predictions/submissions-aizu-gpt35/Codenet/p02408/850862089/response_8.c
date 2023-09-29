#include <stdio.h>
int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark, c;
  scanf("%d ", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf("%c%d%c", &Mark, &Num, &c);
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
  for (j = 0; j < 4; j++) {
    for (i = 0; i < 13; i++) {
      if (Cards[j][i] != 1) {
        printf("%c %d\n", "SHCD"[j], i + 1);
      }
    }
  }
  return 0;
}