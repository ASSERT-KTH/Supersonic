#include <iostream>
#include <complex>

using P = std::complex<double>;

P project(const P& a, const P& b, const P& c) {
  P temp_b = b - a;
  P temp_c = c - a;
  return a + temp_b * std::real(temp_c / temp_b);
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    std::cout << std::setprecision(8) << std::fixed << p.real() << " " << p.imag() << "\n";
  }

  return 0;
}