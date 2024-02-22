#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int Cards[4][13] = {{0}};
  int i, j, n, Num;
  char Mark;

  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Error: Invalid input\n");
    exit(1);
  }

  for (i = 0; i < 2 * n; i++) {
    if (scanf(" %c%d", &Mark, &Num) != 2) {
      fprintf(stderr, "Error: Invalid input\n");
      exit(1);
    }

    if (Num < 1 || Num > 13) {
      fprintf(stderr, "Error: Invalid card number\n");
      exit(1);
    }

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
      default:
        fprintf(stderr, "Error: Invalid card mark\n");
        exit(1);
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        switch (i) {
          case 0:
            printf("S %d\n", j + 1);
            break;
          case 1:
            printf("H %d\n", j + 1);
            break;
          case 2:
            printf("C %d\n", j + 1);
            break;
          case 3:
            printf("D %d\n", j + 1);
            break;
        }
      }
    }
  }

  return 0;
}