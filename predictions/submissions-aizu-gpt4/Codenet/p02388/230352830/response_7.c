#include <stdio.h>
int main(void) {
  int x;
  scanf("%d", &x);
  x *= x; // Multiplication is performed once
  printf("%d\n", x * x);
  return 0;
}