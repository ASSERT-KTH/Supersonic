#include <stdio.h>

int main(void) {
  int Cards[52] = {0};
  int i, n, Num;
  char Mark;
  
  scanf("%d", &n);
  
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &Mark, &Num);
    
    Cards[(Num - 1) + (Mark - 'S') * 13] = 1;
  }
  
  for (i = 0; i < 52; i++) {
    int suit = i / 13;
    int number = i % 13 + 1;
    
    if (Cards[i] != 1) {
      if (suit == 0) {
        printf("S %d\n", number);
      } else if (suit == 1) {
        printf("H %d\n", number);
      } else if (suit == 2) {
        printf("C %d\n", number);
      } else if (suit == 3) {
        printf("D %d\n", number);
      }
    }
  }
  
  return 0;
}