#include <iostream>
#include <cmath>

int main() {
  double r, s, l;
  std::cin >> r;
  s = r * r * M_PI;
  l = 2 * r * M_PI;
  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;
  return 0;
}