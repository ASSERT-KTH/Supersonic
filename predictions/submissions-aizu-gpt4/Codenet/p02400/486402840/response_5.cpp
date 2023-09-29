#include <iostream>

int main() {
  double r;
  std::cin >> r;
  const double PI = 3.141592653589;
  double s = PI * r * r;
  double l = 2 * PI * r;
  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;
  return 0;
}