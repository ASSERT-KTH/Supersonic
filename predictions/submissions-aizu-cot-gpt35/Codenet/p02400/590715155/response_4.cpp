#include <cstdio>
#include <cmath>

int main() {
  double PI = M_PI;
  double r;
  std::cin >> r;
  std::cout << PI * r * r << " " << 2 * PI * r << "\n";
}