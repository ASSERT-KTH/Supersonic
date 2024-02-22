#include <iostream>
#include <iomanip>

int main() {
  constexpr double PI = 3.141592653589;
  double r;
  
  std::cin >> r;
  
  double area = PI * r * r;
  double circumference = 2 * PI * r;
  
  std::cout << std::setprecision(6) << std::fixed;
  std::cout << area << " " << circumference << std::endl;
  
  return 0;
}