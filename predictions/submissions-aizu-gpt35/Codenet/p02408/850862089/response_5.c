#include <stdio.h>
int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark;
  scanf("%d", &n);
  getchar(); // consume newline character
  for (i = 0; i < 2 * n; i++) {
    scanf("%c%d", &Mark, &Num);
    getchar(); // consume newline character
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
  for (j = 0; j < 13; j++) {
    if (Cards[0][j] != 1) {
      printf("S %d\n", j+1);
    }
    if (Cards[1][j] != 1) {
      printf("H %d\n", j+1);
    }
    if (Cards[2][j] != 1) {
      printf("C %d\n", j+1);
    }
    if (Cards[3][j] != 1) {
      printf("D %d\n", j+1);
    }
  }
  if (Cards[0][13] != 1) {
    printf("S %d\n", 14);
  }
  if (Cards[1][13] != 1) {
    printf("H %d\n", 14);
  }
  if (Cards[2][13] != 1) {
    printf("C %d\n", 14);
  }
  if (Cards[3][13] != 1) {
    printf("D %d\n", 14);
  }
  return 0;
}