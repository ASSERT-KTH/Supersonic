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
  P ba(bx - ax, by - ay);
  while (n--) {
    cin >> cx >> cy;
    P ac(cx - ax, cy - ay);
    P p = a + ba * real(ac / ba);
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}