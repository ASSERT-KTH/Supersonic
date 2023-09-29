#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *Cards = calloc(4*14, sizeof(int));
  int i, j, n, Num;
  char Mark;
  scanf("%d", &n);
  getchar();
  for (i = 0; i < 2 * n; i++) {
    scanf("%c ", &Mark);
    scanf("%d", &Num);
    Cards[(int)Mark * 14 + Num - 1] = 1;
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (!Cards[i*14+j]) {
        printf("%c %d\n", "SHCD"[i], j+1);
      }
    }
  }
  free(Cards);
  return 0;
}