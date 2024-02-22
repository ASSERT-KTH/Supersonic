#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  // Print the area (a*b) and perimeter (2*(a+b)) directly
  printf("%d %d\n", a*b, 2*(a+b));
  return 0;
}