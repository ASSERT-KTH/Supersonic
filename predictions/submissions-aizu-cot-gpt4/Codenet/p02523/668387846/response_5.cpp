#include <complex>
#include <cstdio>
using namespace std;
int main() {
  complex<double> P1, P2;
  scanf("%lf %lf %lf %lf", &P1.real(), &P1.imag(), &P2.real(), &P2.imag());
  printf("%.5f\n", abs(P1 - P2));
  return 0;
}