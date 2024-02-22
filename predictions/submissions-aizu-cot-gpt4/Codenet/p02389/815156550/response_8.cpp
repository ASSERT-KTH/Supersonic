#include <iostream>
int main() {
  int a, b;
  std::cin >> a >> b;
  int product = a * b;
  int sum = 2 * (a + b);
  std::cout << product << " " << sum << std::endl;
}