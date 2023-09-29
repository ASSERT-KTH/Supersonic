#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b;
  area *= 2;
  printf("%d %d\n", area, area);
  return 0;
}
