#include <iostream>
#include <complex>
#include <iomanip>

typedef std::complex<float> P;

P project(P a, P b, P c) {
  return a + (b - a) * std::real(c / (b - a));
}

int main() {
  int n;
  float ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    std::cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    std::cout << std::fixed << std::setprecision(8) << p.real() << ' ' << p.imag() << '\n';
  }
  return 0;
}