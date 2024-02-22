#include <iostream>
#include <iomanip>

int main() {
  double r;
  std::cin >> r;

  const double pi = 3.141592653589;
  double area = r * r * pi;
  double circumference = 2 * r * pi;

  std::cout << std::fixed << std::setprecision(8) << area << " " << circumference << std::endl;

  return 0;
}