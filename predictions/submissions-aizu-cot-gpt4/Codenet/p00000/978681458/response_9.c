#include <stdio.h>
int main(void) {
  int i, j, mult;
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      mult = i * j;
      printf("%d", i);
      putchar('x');
      printf("%d", j);
      putchar('=');
      printf("%d\n", mult);
    }
  }
  return (0);
}