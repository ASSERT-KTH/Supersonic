#include <complex>
#include <iostream>
using namespace std;
int main() {
  double r1, i1, r2, i2;
  cin >> r1 >> i1 >> r2 >> i2;
  complex<double> P1(r1, i1), P2(r2, i2);
  cout.precision(5);
  cout << abs(P1 - P2) << endl;
  return 0;
}