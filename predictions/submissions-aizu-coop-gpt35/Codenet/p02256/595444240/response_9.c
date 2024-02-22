#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b) {
  unsigned int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int main() {
  unsigned int a, b;
  printf("Enter two positive integers: ");
  scanf("%u%u", &a, &b);
  
  unsigned int result = gcd(a, b);
  
  printf("The greatest common divisor is: %u\n", result);
  return 0;
}