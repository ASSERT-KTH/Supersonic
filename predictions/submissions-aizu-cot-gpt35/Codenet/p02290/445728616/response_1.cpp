#include <iostream>
#include <complex>
#include <iomanip>

typedef std::complex<double> Complex;

Complex project(Complex a, Complex b, Complex c) {
  return a + b * std::real(c / b);
}

int main() {
  double ax, ay, bx, by, cx, cy;
  int n;

  std::cin >> ax >> ay >> bx >> by >> n;

  while (n--) {
    std::cin >> cx >> cy;
    Complex p = project(Complex(ax, ay), Complex(bx, by), Complex(cx, cy));
    std::cout << std::fixed << std::setprecision(8) << p.real() << ' ' << p.imag() << '\n';
  }

  return 0;
}