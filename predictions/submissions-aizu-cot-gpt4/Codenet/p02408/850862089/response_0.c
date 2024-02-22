#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int n, Num;
  char Mark;
  
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c", &Mark);
    scanf("%d", &Num);
    
    switch(Mark) {
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
  
  char cardTypes[4] = {'S', 'H', 'C', 'D'};
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 13; j++) {
      if (Cards[i][j - 1] != 1) {
        printf("%c %d\n", cardTypes[i], j);
      }
    }
  }
  
  return 0;
}