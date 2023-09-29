#include <stdio.h>
#include <string.h>

int main(void) {
  int Cards[4][14] = {{0}};
  int i, j, n, Num;
  char Mark;
  
  scanf("%d", &n);
  getchar(); // consume newline
  
  for (i = 0; i < 2 * n; i++) {
    scanf("%c%d", &Mark, &Num);
    getchar(); // consume newline
    
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
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] == 0) {
        printf("%c %d\n", "SHCD"[i], j + 1);
      }
    }
  }
  
  return 0;
}