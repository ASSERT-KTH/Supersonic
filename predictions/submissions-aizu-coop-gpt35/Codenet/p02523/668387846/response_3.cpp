#include <complex>
#include <cstdio>

int main() {
  std::complex<double> P1, P2;
  std::scanf("%lf %lf %lf %lf",
              &P1.real(), &P1.imag(), &P2.real(), &P2.imag());
  std::printf("%.5f\n", std::abs(P1 - P2));
  return 0;
}