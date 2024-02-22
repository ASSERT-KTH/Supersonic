#include <iostream>
#include <cmath>

struct Point {
  double real;
  double imag;
};

int main() {
  Point P1, P2;
  std::cin >> P1.real >> P1.imag >> P2.real >> P2.imag;
  
  double distance = std::sqrt((P1.real - P2.real)*(P1.real - P2.real) + (P1.imag - P2.imag)*(P1.imag - P2.imag));
  
  std::cout << std::fixed << std::setprecision(5) << distance << std::endl;

  return 0;
}