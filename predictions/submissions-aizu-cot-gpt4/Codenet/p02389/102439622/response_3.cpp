#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b, c = a * 2 + b * 2;
  printf("%d ", area);
  printf("%d\n", c);
}