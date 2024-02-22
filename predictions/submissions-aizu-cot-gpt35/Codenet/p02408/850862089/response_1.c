#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int j, n, Num;
  char Mark;

  scanf("%d", &n);
  
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

  for (j = 0; j < 14; j++) {
    if (Cards[0][j] != 1) {
      printf("S %d\n", j + 1);
    }
    if (Cards[1][j] != 1) {
      printf("H %d\n", j + 1);
    }
    if (Cards[2][j] != 1) {
      printf("C %d\n", j + 1);
    }
    if (Cards[3][j] != 1) {
      printf("D %d\n", j + 1);
    }
  }

  return 0;
}