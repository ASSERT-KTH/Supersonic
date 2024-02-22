#include <iostream>

int main() {
  unsigned long long factorial = 1;
  int n;

  std::cin >> n;

  for (int i = 2; i <= n; i += 2) {
    factorial *= i * (i + 1);
  }

  if (n % 2 != 0) {
    factorial *= n;
  }

  std::cout << factorial << std::endl;

  return 0;
}