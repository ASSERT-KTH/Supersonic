#include <iostream>

int main() {
  double r, s, l;
  std::cin >> r;
  constexpr double x = 3.141592653589;
  s = r * r * x;
  l = x * (r + r);
  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;
}