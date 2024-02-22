#include <iostream>
#include <complex>
using namespace std;

using P = complex<double>;

P project(P a, P b, P c) {
  b -= a, c -= a;
  return a + b * real(c / b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

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