#include <iostream>

int main() {
  const double PI = 3.141592653589;
  double r;
  std::cin >> r;
  
  double area = PI * r * r;
  double circumference = 2 * PI * r;
  
  std::cout << area << " " << circumference << std::endl;
  
  return 0;
}