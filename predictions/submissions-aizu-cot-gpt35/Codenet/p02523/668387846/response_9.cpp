#include <complex>
#include <iostream>
#include <iomanip>

int main() {
  std::complex<double> P1, P2;
  std::cin >> P1.real() >> P1.imag() >> P2.real() >> P2.imag();
  std::cout << std::setprecision(5) << std::abs(P1 - P2) << std::endl;
  return 0;
}