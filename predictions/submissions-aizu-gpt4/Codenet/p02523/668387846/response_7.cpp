#include <cmath>
#include <complex>
#include <cstdio>
using namespace std;
int main() {
  double real1, imag1, real2, imag2;
  cin >> real1 >> imag1 >> real2 >> imag2;
  complex<double> P1(real1, imag1), P2(real2, imag2);
  printf("%.5f\n", abs(P1 - P2));
  return 0;
}