#include <stdio.h>
int main(void) {
  int x, square;
  scanf("%d", &x);
  square = x * x; // Calculate the square of the number
  printf("%d\n", x * square); // Calculate the cube using the square
  return 0;
}