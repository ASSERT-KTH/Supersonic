#include <stdio.h>

int main(void) {
  int x;

  printf("Enter a number: ");
  scanf("%d", &x);

  printf("Cube: %d\n", x ** 3);

  return 0;
}