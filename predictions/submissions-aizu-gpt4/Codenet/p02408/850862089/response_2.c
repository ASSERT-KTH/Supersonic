#include <stdio.h>
#define TOTAL_CARDS 14

int main(void) {
  int Cards[4][TOTAL_CARDS] = { 0 };
  int n, Num;
  char Mark;
  scanf("%d", &n);
  while(n--){
    scanf(" %c", &Mark);
    scanf("%d", &Num);
    switch(Mark){
        case 'S': Cards[0][Num - 1] = 1; break;
        case 'H': Cards[1][Num - 1] = 1; break;
        case 'C': Cards[2][Num - 1] = 1; break;
        case 'D': Cards[3][Num - 1] = 1; break;
    }
  }
  char marks[] = {'S', 'H', 'C', 'D'};
  for(int m=0; m<4; m++){
      for(int j=0; j<TOTAL_CARDS; j++){
          if(Cards[m][j] != 1)
              printf("%c %d\n",marks[m],j+1);
      }
  }
  return 0;
}