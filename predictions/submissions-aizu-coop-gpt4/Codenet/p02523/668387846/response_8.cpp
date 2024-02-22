#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double a, b;
  complex<double> P1, P2;
  cin >> a >> b;
  P1 = complex<double>(a, b);
  cin >> a >> b;
  P2 = complex<double>(a, b);
  printf("%.5f\n", abs(P1 - P2));
  return 0;
}