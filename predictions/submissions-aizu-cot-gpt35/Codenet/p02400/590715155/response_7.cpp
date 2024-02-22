#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  const double PI = M_PI;
  double r;
  std::cin >> r;
  std::cout << std::fixed << std::setprecision(6) << PI * r * r << " " << 2 * PI * r << "\n";
  return 0;
}