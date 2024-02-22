#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  double r;
  std::cin >> r;
  
  double area = M_PI * r * r;
  double circumference = 2 * M_PI * r;
  
  std::cout << std::fixed << std::setprecision(10);
  std::cout << area << " " << circumference << std::endl;
  
  return 0;
}