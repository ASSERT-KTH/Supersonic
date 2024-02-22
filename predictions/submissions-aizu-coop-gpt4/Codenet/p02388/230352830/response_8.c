#include <stdio.h>
int main(void) {
  int x;
  scanf("%d", &x);
  printf("%d\n", x << 3); // This is equivalent to x*8 if x is a power of 2.
  return 0;
}