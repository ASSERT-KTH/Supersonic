#include <stdio.h>

int main(void) {
  int Cards[52] = {0};
  int n, Num, index;
  char Mark;

  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c %d", &Mark, &Num);
    index = (Mark - 'S') * 13 + (Num - 1);
    Cards[index] = 1;
  }

  for (int j = 0; j < 52; j++) {
    if (Cards[j] != 1) {
      Mark = (j / 13) + 'S';
      Num = (j % 13) + 1;
      printf("%c %d\n", Mark, Num);
    }
  }

  return 0;
}