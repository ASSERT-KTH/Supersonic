#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
int main() {
  double P1_real, P1_imag, P2_real, P2_imag;
  cin >> P1_real >> P1_imag >> P2_real >> P2_imag;
  complex<double> P1(P1_real, P1_imag), P2(P2_real, P2_imag);
  cout.precision(5);
  cout << fixed << abs(P1 - P2) << endl;
  return 0;
}