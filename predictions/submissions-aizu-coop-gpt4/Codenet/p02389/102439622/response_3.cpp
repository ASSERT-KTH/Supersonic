#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int area = a * b;  // Calculation of the area
  int perimeter = (a << 1) + (b << 1);  // Calculation of the perimeter using bitwise shift instead of multiplication

  printf("%d %d\n", area, perimeter);

  return 0;
}