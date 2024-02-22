#include <stdio.h>

int main(void) {
  int Cards[4][14] = {0};
  int i, j, n, Num;
  int Marks[256] = {0};
  char Mark;

  Marks['S'] = 0;
  Marks['H'] = 1;
  Marks['C'] = 2;
  Marks['D'] = 3;

  scanf("%d", &n);
  for (i = 0; i < 2 * n; i++) {
    scanf(" %c%d", &Mark, &Num);
    Cards[Marks[Mark]][Num - 1] = 1;
  }

  char SuitLabels[] = {'S', 'H', 'C', 'D'};
  for (int suit = 0; suit < 4; suit++) {
    for (j = 0; j < 13; j++) {
      if (Cards[suit][j] != 1) {
        printf("%c %d\n", SuitLabels[suit], j + 1);
      }
    }
  }

  return 0;
}