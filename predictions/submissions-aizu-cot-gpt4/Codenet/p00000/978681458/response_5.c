#include <stdio.h>

int main(void) {
  int i, j, product;
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      product = i * j;
      printf("%d", i);
      putchar('x');
      printf("%d", j);
      putchar('=');
      printf("%d", product);
      putchar('\n');
    }
  }
  return (0);
}