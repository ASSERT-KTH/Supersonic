#include <iostream>
#include <iomanip>

int main() {
  const double PI = 3.141592653589;
  double r;
  std::ios_base::sync_with_stdio(false);
  
  std::cin >> r;
  
  double area = PI * r * r;
  double circumference = 2 * PI * r;
  
  std::cout << std::fixed << std::setprecision(6); // Output precision set to 6 decimal places
  std::cout << area << " " << circumference << "\n";
  
  return 0;
}