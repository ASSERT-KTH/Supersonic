#include <stdio.h>
int main(void) {
  int Cards[52] = {};
  int i, n, Num;
  char Mark;
  scanf("%d", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf("%c ", &Mark);
    scanf("%d", &Num);
    switch (Mark) {
      case 'S':
        Cards[Num - 1] = 1;
        break;
      case 'H':
        Cards[Num + 12] = 1;
        break;
      case 'C':
        Cards[Num + 25] = 1;
        break;
      case 'D':
        Cards[Num + 38] = 1;
        break;
    }
  }
  for (i = 0; i < 52; i++) {
    if (Cards[i] != 1) {
      if (i < 13) {
        printf("S %d\n", i + 1);
      } else if (i < 26) {
        printf("H %d\n", i - 12);
      } else if (i < 39) {
        printf("C %d\n", i - 25);
      } else {
        printf("D %d\n", i - 38);
      }
    }
  }
  return 0;
}