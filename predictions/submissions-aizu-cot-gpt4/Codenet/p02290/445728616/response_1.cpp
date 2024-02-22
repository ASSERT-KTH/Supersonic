#include <iostream>
#include <complex>
#include <cstdio>
using namespace std;
typedef complex<double> P;

P project(P a, P b, P c) {
  b -= a, c -= a;
  return a + b * real(c / b);
}

int main() {
  int n;
  double ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by >> n;
  P a(ax, ay), b(bx, by);
  while (n--) {
    double cx, cy;
    cin >> cx >> cy;
    P c(cx, cy);
    P p = project(a, b, c);
    cout << fixed << setprecision(8) << p.real() << " " << p.imag() << "\n";
  }
  return 0;
}