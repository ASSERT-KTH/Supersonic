#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
  double r, s, l;
  std::cin >> r;
  s = M_PI * r * r;
  l = 2 * M_PI * r;
  std::cout << std::setprecision(8) << s << " " << l << std::endl;
}