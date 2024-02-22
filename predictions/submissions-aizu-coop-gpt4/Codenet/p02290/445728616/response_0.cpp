#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> P;

P project(const P& a, const P& b, const P& c) {
  P b_new = b - a, c_new = c - a;
  return a + b_new * real(c_new / b_new);
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    cout << fixed << setprecision(8) << p.real() << " " << p.imag() << "\n";
  }
  return 0;
}