#include <cmath>
#include <cstdio>

int main() {
  double r, s, l;
  std::cin >> r;
  s = r * r * M_PI;
  l = 2 * M_PI * r;
  std::printf("%.6lf %.6lf\n", s, l);
}