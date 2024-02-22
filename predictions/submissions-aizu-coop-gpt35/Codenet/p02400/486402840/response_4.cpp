#include <iostream>

constexpr double PI = 3.141592653589;

int main() {
  double r;
  std::cin >> r;
  
  double s = r * r * PI;
  double l = 2 * r * PI;

  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;
}