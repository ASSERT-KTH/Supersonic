#include <iostream>
#include <iomanip>

int main() {
  const double PI = 3.141592653589;
  double r;
  std::cin >> r;
  std::cout << std::fixed << std::setprecision(6) << PI * r * r << " " << 2 * PI * r << std::endl;
  return 0;
}