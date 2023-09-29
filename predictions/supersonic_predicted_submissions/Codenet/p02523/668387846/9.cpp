#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  complex<double> P1, P2;
  cin >> P1.real() >> P1.imag() >> P2.real() >> P2.imag();
  cout << abs(P1 - P2) << endl;
  return 0;
}
