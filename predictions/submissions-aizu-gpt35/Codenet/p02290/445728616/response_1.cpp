#include <iostream>
#include <complex>
using namespace std;

typedef complex<double> P;

P project(const P& a, const P& b, const P& c) {
  P vector1 = b - a;
  P vector2 = c - a;
  return a + vector1 * real(vector2 / vector1);
}

int main() {
  double ax, ay, bx, by, cx, cy;
  int n;
  cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    cout << fixed << setprecision(8) << p.real() << " " << p.imag() << endl;
  }
  return 0;
}