#include <stdio.h>

int main() {
  int a, b, c, i;
  scanf("%d%d", &a, &b);

  // Move the modulo operation inside the while loop condition
  while ((c = a % b) > 0) {
    a = b;
    b = c;
  }

  printf("%d\n", a);
}