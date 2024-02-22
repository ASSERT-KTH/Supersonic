#include <stdio.h>

int main(void) {
  int Cards[4][13] = {{0}};
  int i, j, n;
  char input[3], Mark;
  
  scanf("%d", &n);
  
  for (i = 0; i < 2 * n; i++) {
    scanf("%s", input);
    
    Mark = input[0];
    int Num = input[1] - '0';
    
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
  
  char suits[4] = {'S', 'H', 'C', 'D'};
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        printf("%c %d\n", suits[i], j + 1);
      }
    }
  }
  
  return 0;
}