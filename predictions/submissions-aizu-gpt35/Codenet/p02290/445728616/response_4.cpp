#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> P;
P project(const P& a, const P& b, const P& c) {
  P b_a = b - a, c_a = c - a;
  return a + b_a * (conj(c_a) / conj(b_a));
}
int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}