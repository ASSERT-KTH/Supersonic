#include <iostream>
#include <cmath>

int main() {
  const double PI = 3.14159;
  double r;
  std::cin >> r;
  std::cout << (PI * r * r) << " " << (2 * PI * r) << std::endl;
  return 0;
}