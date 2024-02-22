#include <cstdio>

int main() {
  double r, s, l;
  std::cin >> r;
  s = r * r * 3.141592653589;
  l = 2 * 3.141592653589 * r;
  std::cout << std::fixed;
  std::cout.precision(8);
  std::cout << s << " " << l << "\n";
}