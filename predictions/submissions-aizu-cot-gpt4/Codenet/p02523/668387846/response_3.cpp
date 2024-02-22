#include <cstdio>
#include <complex>
#include <cmath>

int main() {
  std::complex<double> P1, P2;
  scanf("%lf %lf", &P1.real(), &P1.imag());
  scanf("%lf %lf", &P2.real(), &P2.imag());
  printf("%.5f\n", std::abs(P1 - P2));
  return 0;
}