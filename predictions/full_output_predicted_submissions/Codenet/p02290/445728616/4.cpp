#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
P project(P a, P b, P c) {
  b -= a, c -= a;
  return a + b * real(c / b);
}
int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  while (n--) {
    cin >> cx >> cy;
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    printf("%.8lf %.8f\n", p.real(), p.imag());
  }
  return 0;
}
