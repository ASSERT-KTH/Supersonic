#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  int square = x * x; // Calculate the square of x
  printf("%d\n", square * x); // Calculate the cube by multiplying the square by x
  return 0;
}