#include <stdio.h>

int main() {
  int a, b, c, gcd;
  
  // Efficient input handling
  scanf("%d%d", &a, &b);

  // Calculate GCD using the Euclidean algorithm
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  
  gcd = a;
  
  printf("%d\n", gcd);
  return 0;
}