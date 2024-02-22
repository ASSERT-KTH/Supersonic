#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b;
  int perimeter = (a + b) * 2;
  printf("%d ", area);
  printf("%d\n", perimeter);
}