#include <iostream>
#include <cstdio>

// Helper function to calculate cube using exponentiation by squaring
int cube(int x) {
  int result = 1;
  int base = x;
  int exponent = 3;
  
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result *= base;
    }
    base *= base;
    exponent /= 2;
  }
  
  return result;
}

int main() {
  int x;
  std::cin >> x;
  
  int y = cube(x);
  
  printf("%d\n", y);
  
  return 0;
}