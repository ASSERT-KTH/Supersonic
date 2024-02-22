#include <stdio.h>

int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark;
  char types[] = {'S', 'H', 'C', 'D'}; // Map indices to card types

  scanf("%d", &n);

  for (i = 0; i < 2 * n; i++) {
    scanf(" %c", &Mark); // Note: added space before %c to skip whitespace
    scanf("%d", &Num);
    Cards[Mark - 'S'][Num - 1] = 1; // Use ASCII value to calculate index
  }

  // Combine printing loops into a single loop
  for (i = 0; i < 4; i++) {
    for (j = 1; j < 14; j++) {
      if (Cards[i][j - 1] != 1) {
        printf("%c %d\n", types[i], j); // Use array to print card type
      }
    }
  }

  return 0;
}