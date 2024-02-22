#include <stdio.h>

int main(void) {
  int cards[4][13] = {{0}}; // Initialize array with zeroes
  int i, n, num;
  char mark;
  char marks[] = {'S', 'H', 'C', 'D'};

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf(" %c", &mark); // Add space before %c to consume any whitespace
    scanf("%d", &num);
    num--; // Subtract 1 right away

    switch(mark) {
      case 'S': cards[0][num] = 1; break;
      case 'H': cards[1][num] = 1; break;
      case 'C': cards[2][num] = 1; break;
      case 'D': cards[3][num] = 1; break;
      default: break;
    }
  }

  for (i = 0; i < 4; i++) {
    for (n = 0; n < 13; n++) {
      if (cards[i][n] != 1) {
        printf("%c %d\n", marks[i], n+1);
      }
    }
  }

  return 0;
}
