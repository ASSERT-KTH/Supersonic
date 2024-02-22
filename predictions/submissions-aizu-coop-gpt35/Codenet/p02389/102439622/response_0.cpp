#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  // Calculate the area
  printf("%d ", a * b);

  // Calculate the perimeter
  printf("%d\n", (a + b) * 2);

  return 0;
}