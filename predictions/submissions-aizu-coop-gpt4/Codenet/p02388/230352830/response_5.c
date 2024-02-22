#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  int x_square = x * x;  // Calculate x^2 only once and reuse it.
  printf("%d\n", x_square * x);  // Use the stored x^2 value to compute x^3.
  return 0;
}