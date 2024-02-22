#include <iostream>

int main() {
  unsigned long long a = 1;
  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    a *= i;
  }

  std::cout << a << std::endl;
  return 0;
}