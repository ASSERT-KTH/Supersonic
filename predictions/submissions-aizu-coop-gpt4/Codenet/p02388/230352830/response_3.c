#include <stdio.h>
int main(void) {
  int x, square_x;
  scanf("%d", &x);
  square_x = x * x;  // Compute the square of x
  printf("%d\n", square_x * x);  // Multiply the square of x by x to get the cube
  return 0;
}