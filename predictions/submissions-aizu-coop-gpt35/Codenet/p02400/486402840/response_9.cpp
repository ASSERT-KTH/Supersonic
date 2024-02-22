#include <iostream>

int main() {
  double r, s, l;
  std::cin >> r;

  const double x = 3.14159265;  // Reduced precision to 8 decimal places

  s = r * r * x;
  l = x * (r + r);

  std::cout.precision(8);  // Set precision to 8 decimal places
  std::cout << std::fixed << s << " " << l << std::endl;

  return 0;
}