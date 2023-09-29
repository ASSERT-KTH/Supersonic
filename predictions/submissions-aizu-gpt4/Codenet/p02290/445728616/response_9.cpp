#include <iostream>
#include <complex>

typedef std::complex<double> P;

inline P project(const P& a, const P& b, const P& c) {
  P b1 = b - a, c1 = c - a;
  return a + b1 * std::real(c1 / b1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  double ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    std::cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    std::cout << std::fixed << std::setprecision(8) << p.real() << " " << p.imag() << "\n";
  }
  return 0;
}