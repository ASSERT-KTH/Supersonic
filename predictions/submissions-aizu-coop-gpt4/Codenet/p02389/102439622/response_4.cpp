#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  
  // Compute area and perimeter using optimized calculations
  int area = a * b;
  int perimeter = 2 * (a + b);  // Factored out the common factor of 2
  
  printf("%d %d\n", area, perimeter);
  
  return 0;
}