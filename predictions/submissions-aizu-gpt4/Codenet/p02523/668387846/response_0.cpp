#include <complex>
#include <iostream>

int main() {
  std::complex<double> P1, P2;
  double real1, imag1, real2, imag2;
  std::cin >> real1 >> imag1 >> real2 >> imag2;
  P1.real(real1); P1.imag(imag1);
  P2.real(real2); P2.imag(imag2);
  std::cout.precision(5);
  std::cout << std::fixed << std::abs(P1 - P2) << '\n';
  return 0;
}