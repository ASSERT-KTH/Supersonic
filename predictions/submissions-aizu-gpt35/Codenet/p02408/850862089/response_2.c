#include <stdio.h>
int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark, space;
  scanf("%d", &n);
  scanf("%c", &space); // consume the newline character left in input buffer
  for (i = 0; i < 2 * n; i++) {
    scanf("%c", &Mark);
    scanf("%d", &Num);
    Cards[Mark - 'S'][Num - 1] = 1;
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (Cards[i][j] != 1) {
        printf("%c %d\n", i + 'S', j + 1);
      }
    }
  }
  return 0;
}