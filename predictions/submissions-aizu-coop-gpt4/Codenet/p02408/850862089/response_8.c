#include <stdio.h>
int main(void) {
  int Cards[4][13] = {0}; // No need for {{}} initializer
  int i, j, n, Num;
  char Mark;
  scanf("%d", &n);
  // Combined the two scanf operations into one
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &Mark, &Num);
    switch (Mark) { // Switch statement instead of if-else chain
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
  // Combined the four for loops into one
  for (i = 0; i < 4; i++) {
    for (j = 1; j <= 13; j++) {
      if (Cards[i][j - 1] != 1) {
        switch (i) { // Switch statement to determine the suit
          case 0:
            printf("S %d\n", j);
            break;
          case 1:
            printf("H %d\n", j);
            break;
          case 2:
            printf("C %d\n", j);
            break;
          case 3:
            printf("D %d\n", j);
            break;
        }
      }
    }
  }
  return 0;
}