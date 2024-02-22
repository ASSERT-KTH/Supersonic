#include <iostream>

int main() {
  long long a, b;
  std::cin >> a >> b;

  long long product = a * b;
  long long sum = (a + b) * 2;

  std::cout << product << " " << sum << std::endl;

  return 0;
}