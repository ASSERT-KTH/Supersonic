#include <stdio.h>
int main(void) {
  int Cards[4][14] = {{0}};
  int n, Num;
  char Mark;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c", &Mark);
    scanf("%d", &Num);
    switch (Mark) {
      case 'S':
        Cards[0][Num - 1] = 1;
        break;
      case 'H':
        Cards[1][Num - 1] = 1;
        break;
      case 'C':
        Cards[2][Num - 1] = 1;
        break;
      case 'D':
        Cards[3][Num - 1] = 1;
        break;
    }
  }
  const char *Marks = "SHCD";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 14; j++) {
      if (Cards[i][j] != 1) {
        printf("%c %d\n", Marks[i], j + 1);
      }
    }
  }
  return 0;
}