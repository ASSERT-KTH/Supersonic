#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int i, n, Num;
  char Mark;
  scanf("%d", &n);
  
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c", &Mark);
    scanf("%d", &Num);
    Cards[Mark=='S'?0:(Mark=='H'?1:(Mark=='C'?2:3))][Num - 1] = 1;
  }
  
  char marks[4] = {'S', 'H', 'C', 'D'};
  for (i = 0; i < 4; i++) {
    for (Num = 1; Num <= 14; Num++) {
      if (Cards[i][Num - 1] != 1) printf("%c %d\n", marks[i], Num);
    }
  }
  return 0;
}