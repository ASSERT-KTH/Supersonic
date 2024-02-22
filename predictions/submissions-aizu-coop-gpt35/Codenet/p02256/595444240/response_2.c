#include <stdio.h>

int main() {
  int a, b;
  
  // Input Validation
  if (scanf("%d%d", &a, &b) != 2) {
    printf("Invalid input\n");
    return 1;
  }
  
  // Variable Initialization
  int gcd = 1;
  
  // Optimized GCD Calculation
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  
  gcd = a;

  printf("%d\n", gcd);
  return 0;
}