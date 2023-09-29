#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{0}};
  int n, Num;
  char Mark;

  scanf("%d", &n);
  while(n-->0) {
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

  const char* suite[] = {"S", "H", "C", "D"};
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 14; j++) {
      if (Cards[i][j] != 1) {
        printf("%s %d\n", suite[i], j+1);
      }
    }
  }
  
  return 0;
}