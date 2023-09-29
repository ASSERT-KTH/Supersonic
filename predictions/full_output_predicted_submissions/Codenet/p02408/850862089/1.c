#include <stdio.h>
int main(void) {
  intcards[4][14] = {{}};
  int i, j, n, Num;
  char Mark;
  scanf("%d", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf("%c ", &Mark);
    scanf("%d", &Num);
    if (Mark == 'S') {
     cards[0][Num - 1] = 1;
    } else if (Mark == 'H') {
     cards[1][Num - 1] = 1;
    } else if (Mark == 'C') {
     cards[2][Num - 1] = 1;
    } else if (Mark == 'D') {
     cards[3][Num - 1] = 1;
    }
  }
  for (j = 1; j < 14; j++) {
    if (Cards[0][j - 1] != 1) {
      printf("S %d\n", j);
    }
  }
  for (j = 1; j < 14; j++) {
    if (Cards[1][j - 1] != 1) {
      printf("H %d\n", j);
    }
  }
  for (j = 1; j < 14; j++) {
    if (Cards[2][j - 1] != 1) {
      printf("C %d\n", j);
    }
  }
  for (j = 1; j < 14; j++) {
    if (Cards[3][j - 1] != 1) {
      printf("D %d\n", j);
    }
  }
  return 0;
}
