#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int j, Mark;
  
  scanf("%d", &Mark);
  while (Mark--) {
    int Num;
    char suit;
    scanf(" %c %d", &suit, &Num);
    
    if (suit == 'S') {
      Cards[0][Num - 1] = 1;
    } else if (suit == 'H') {
      Cards[1][Num - 1] = 1;
    } else if (suit == 'C') {
      Cards[2][Num - 1] = 1;
    } else if (suit == 'D') {
      Cards[3][Num - 1] = 1;
    }
  }
  
  for (int i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        char suit;
        if (i == 0) {
          suit = 'S';
        } else if (i == 1) {
          suit = 'H';
        } else if (i == 2) {
          suit = 'C';
        } else if (i == 3) {
          suit = 'D';
        }
        printf("%c %d\n", suit, j + 1);
      }
    }
  }
  
  return 0;
}