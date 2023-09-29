#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b;
  area = a * 2 + b * 2;
  printf("%d %d\n", area, area);
}
