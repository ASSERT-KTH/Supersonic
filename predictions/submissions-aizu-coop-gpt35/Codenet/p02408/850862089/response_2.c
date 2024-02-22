#include <stdio.h>

int main(void) {
  int Cards[4][14] = {0};
  int i, j, n, Num;
  char Mark;
  
  scanf("%d", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c%d", &Mark, &Num);
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
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        if (i == 0) printf("S ");
        else if (i == 1) printf("H ");
        else if (i == 2) printf("C ");
        else if (i == 3) printf("D ");
        printf("%d\n", j + 1);
      }
    }
  }
  
  return 0;
}