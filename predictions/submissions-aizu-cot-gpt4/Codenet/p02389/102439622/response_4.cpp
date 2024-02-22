#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b;
  int c = 2 * (a + b);
  printf("%d %d\n", area, c);
}