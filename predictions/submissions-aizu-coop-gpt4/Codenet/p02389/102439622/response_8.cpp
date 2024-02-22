#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  // Combine area and perimeter calculation into single printf statement
  printf("%d %d\n", a * b, 2 * (a + b));
  return 0;
}