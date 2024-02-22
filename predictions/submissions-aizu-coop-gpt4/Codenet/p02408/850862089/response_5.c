#include <stdio.h>

int main(void) {
  int cards[4][14] = {0};
  int n, num;
  char mark;

  scanf("%d", &n);

  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &mark, &num);  // combined the two scanf() into one
    switch (mark) {  // replaced if-else conditions with switch case
      case 'S':
        cards[0][num - 1] = 1;
        break;
      case 'H':
        cards[1][num - 1] = 1;
        break;
      case 'C':
        cards[2][num - 1] = 1;
        break;
      case 'D':
        cards[3][num - 1] = 1;
        break;
    }
  }

  char suits[] = {'S', 'H', 'C', 'D'};

  for (int i = 0; i < 4; i++) {  // merged the four loops into a single one
    for (int j = 0; j < 14; j++) {
      if (cards[i][j] != 1) {
        printf("%c %d\n", suits[i], j + 1);  // used pointer to loop through the array
      }
    }
  }
  
  return 0;
}