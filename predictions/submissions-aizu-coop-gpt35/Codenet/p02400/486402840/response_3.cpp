#include <iostream>
#include <cmath>

int main() {
  const double r = []{
    double radius;
    std::cin >> radius;
    return radius;
  }();
  
  const double s = M_PI * r * r;
  const double l = 2 * M_PI * r;

  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;

  return 0;
}