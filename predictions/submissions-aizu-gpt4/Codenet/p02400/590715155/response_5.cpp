#include <iostream>
constexpr double PI = 3.141592653589;
int main() {
  double r;
  std::cin >> r;
  std::cout << PI * r * r << " " << 2 * PI * r << '\n';
  return 0;
}