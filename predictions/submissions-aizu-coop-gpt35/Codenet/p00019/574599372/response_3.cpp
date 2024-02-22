#include <iostream>

unsigned long long factorial(int n) {
  if (n < 2) {
    return 1;
  }

  unsigned long long result = 1;

  // Calculate factorial using loop unrolling
  for (int i = 2; i <= n; i += 2) {
    result *= i;
    if (i + 1 <= n) {
      result *= (i + 1);
    }
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;

  unsigned long long factorialResult = factorial(n);

  std::cout << factorialResult << std::endl;

  return 0;
}