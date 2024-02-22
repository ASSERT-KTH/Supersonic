#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::complex<double> P1, P2;
  std::cin >> P1.real() >> P1.imag() >> P2.real() >> P2.imag();
  std::cout << std::fixed << std::setprecision(5) << std::abs(P1 - P2) << "\n";
  return 0;
}