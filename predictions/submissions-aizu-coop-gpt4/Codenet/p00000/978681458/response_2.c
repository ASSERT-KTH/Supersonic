#include <stdio.h>

int main(void) {
  int i, j, product;
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      product = i * j;  // Calculate the product once and store it
      printf("%dx%d=%d\n", i, j, product);
    }
  }
  return (0);
}