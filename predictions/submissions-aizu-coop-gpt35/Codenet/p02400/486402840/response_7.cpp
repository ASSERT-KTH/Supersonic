#include <iostream>
#include <iomanip>

int main() {
  const double pi = 3.141592653589;
  double r, s, l;
  
  std::cin >> r;
  s = r * r * pi;
  l = 2 * r * pi;

  std::cout << std::fixed << std::setprecision(8) << s << " " << l << std::endl;
  
  return 0;
}