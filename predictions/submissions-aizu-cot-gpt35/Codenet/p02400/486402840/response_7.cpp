#include <iostream>

int main() {
  float r;
  std::cin >> r;
  float s = 3.141592653589 * r * r;
  float l = 3.141592653589 * (r + r);
  std::cout.precision(8);
  std::cout << std::fixed << s << " " << l << std::endl;
}