#include <iostream>

int main() {
  double r, x;
  std::cin >> r;
  x = 3.141592653589;

  double s = r * r * x;
  double l = x * (r + r);

  std::cout << s << " " << l << std::endl;

  return 0;
}