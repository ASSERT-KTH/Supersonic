#include <stdio.h>
#include <stdbool.h>

#define MAX_CARDS 14

int main(void) {
  unsigned long long Cards[4] = {0};
  int i, n, Num;
  char Mark;

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf(" %c%d", &Mark, &Num);
    int suit;
    switch (Mark) {
      case 'S':
        suit = 0;
        break;
      case 'H':
        suit = 1;
        break;
      case 'C':
        suit = 2;
        break;
      case 'D':
        suit = 3;
        break;
    }
    Cards[suit] |= (1ULL << (Num - 1));
  }

  for (i = 0; i < MAX_CARDS - 1; i++) {
    if ((Cards[0] & (1ULL << i)) == 0) {
      printf("S %d\n", i + 1);
    }
  }

  for (i = 0; i < MAX_CARDS - 1; i++) {
    if ((Cards[1] & (1ULL << i)) == 0) {
      printf("H %d\n", i + 1);
    }
  }

  for (i = 0; i < MAX_CARDS - 1; i++) {
    if ((Cards[2] & (1ULL << i)) == 0) {
      printf("C %d\n", i + 1);
    }
  }

  for (i = 0; i < MAX_CARDS - 1; i++) {
    if ((Cards[3] & (1ULL << i)) == 0) {
      printf("D %d\n", i + 1);
    }
  }

  return 0;
}