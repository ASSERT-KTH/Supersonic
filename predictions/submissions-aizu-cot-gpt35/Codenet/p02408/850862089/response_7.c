#include <stdio.h>
#include <string.h>

int main(void) {
  int Cards[4][14];
  int j, n, Num;
  char Mark;

  scanf("%d", &n);

  // Initialize Cards array
  memset(Cards, 0, sizeof(Cards));

  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &Mark, &Num);

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

  for (j = 1; j < 14; j++) {
    for (int suit = 0; suit < 4; suit++) {
      if (Cards[suit][j - 1] != 1) {
        switch (suit) {
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