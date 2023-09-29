#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> P;

inline P project(const P& a, const P& b, const P& c) {
  P b2 = b - a, c2 = c - a;
  return a + b2 * (c2 / b2).real();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(8);
  cout << fixed;
  
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  P a = {ax, ay}, b = {bx, by};
  
  while (n--) {
    cin >> cx >> cy;
    P p = project(a, b, P(cx, cy));
    cout << p.real() << ' ' << p.imag() << '\n';
  }
  return 0;
}