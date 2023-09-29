#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
int main() {
  double r1, r2, i1, i2;
  cin >> r1 >> i1 >> r2 >> i2;
  complex<double> P1(r1, i1), P2(r2, i2);
  printf("%.5f\n", abs(P1 - P2));
  return 0;
}