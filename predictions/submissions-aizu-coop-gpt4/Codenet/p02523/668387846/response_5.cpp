#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  complex<double> P1, P2;
  double real_part, imag_part;

  cin >> real_part >> imag_part;
  P1.real(real_part);
  P1.imag(imag_part);

  cin >> real_part >> imag_part;
  P2.real(real_part);
  P2.imag(imag_part);

  printf("%.5f\n", abs(P1 - P2));
  return 0;
}