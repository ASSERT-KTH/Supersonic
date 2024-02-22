#include <stdio.h>

int main(void) {
  int Cards[52] = {0}; // Optimized for memory usage
  int i, j, n, Num;
  char Mark;

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf(" %c%d%*c", &Mark, &Num); // Modified input reading code

    int suit = (Mark - 'S') * 13;
    Cards[suit + Num - 1] = 1;
  }

  char suits[] = {'S', 'H', 'C', 'D'};

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      int suit = i * 13;
      if (Cards[suit + j] != 1) {
        printf("%c %d\n", suits[i], j + 1);
      }
    }
  }

  return 0;
}