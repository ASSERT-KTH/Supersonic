#include <iostream>

int main() {
  int n;
  std::cin >> n;

  if (n < 0) {
    std::cout << "Factorial is undefined for negative numbers." << std::endl;
    return 0;
  }

  unsigned long long factorial = 1;
  for (int i = 2; i <= n; ++i) {
    factorial *= i;
  }

  std::cout << factorial << '\n';
  return 0;
}