#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  complex<double> P1, P2;
  cin >> P1.real() >> P1.imag() >> P2.real() >> P2.imag();
  printf("%f\n", abs(P1 - P2));
  return 0;
}
