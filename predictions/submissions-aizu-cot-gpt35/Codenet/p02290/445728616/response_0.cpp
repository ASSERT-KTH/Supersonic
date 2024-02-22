#include <complex>
#include <iostream>
#include <iomanip>

typedef std::complex<double> P;

P project(P a, P b, P c) {
  b -= a;
  c -= a;
  return a + b * std::real(c / b);
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    std::cout << std::fixed << std::setprecision(8) << p.real() << " " << p.imag() << std::endl;
  }

  return 0;
}