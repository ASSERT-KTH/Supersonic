#include <stdio.h>
int main(void) {
  int x, x_squared;
  scanf("%d", &x);
  x_squared = x * x;
  printf("%d\n", x_squared * x);
  return 0;
}