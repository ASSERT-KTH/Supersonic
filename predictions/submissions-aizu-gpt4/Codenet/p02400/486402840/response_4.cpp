#include <iostream>
#include <cmath>

int main() {
  double r, s, l;
  std::cin >> r;
  s = M_PI * r * r;
  l = 2 * M_PI * r;
  std::cout.precision(9);
  std::cout << s << " " << l << "\n";
}