#include <stdio.h>
int main(void) {
  int Cards[4][14] = {{}};
  int i, j, n, Num;
  char Mark;
  scanf("%d", &n);
  getchar(); // consume the newline character left in the buffer
  for (i = 0; i < 2 * n; i++) {
    scanf("%c%d ", &Mark, &Num); // read the input with a single scanf call
    Cards[Mark - 'S'][Num - 1] = 1; // simplified assigning to the 2D array
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) { // loop to 13 to simplify the inner if statement
      if (Cards[i][j] != 1) {
        printf("%c %d\n", i + 'S', j + 1); // simplified printing
      }
    }
  }
  return 0;
}