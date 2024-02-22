#include <iostream>
#include <cmath>

int main() {
  double r;
  std::cin >> r;
  std::cout.precision(8);
  std::cout << std::fixed << r * r * M_PI << " " << 2 * r * M_PI << std::endl;
  return 0;
}