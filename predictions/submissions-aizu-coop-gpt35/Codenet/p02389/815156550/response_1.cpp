#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  int result1 = a * b;
  int result2 = a * 2 + b * 2;

  std::cout << result1 << " " << result2 << std::endl;

  return 0;
}