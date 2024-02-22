#include <stdio.h>

int main(void) {
  int Cards[52] = {0};

  int n;
  scanf("%d", &n);

  for (int i = 0; i < 2 * n; i++) {
    char Mark;
    int Num;
    scanf(" %c%d", &Mark, &Num);
    int index = (Mark - 'S') * 13 + Num - 1;
    Cards[index] = 1;
  }

  for (int index = 0; index < 52; index++) {
    if (Cards[index] == 0) {
      int suit = index / 13;
      int number = index % 13 + 1;
      printf("%c %d\n", suit + 'S', number);
    }
  }

  return 0;
}