#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;

P project(P& a, P& b, P& c) {
  b -= a; c -= a;
  P b_reciprocal = 1.0 / b;
  return a + b * real(c * b_reciprocal);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;

  P a, b, c;
  
  while (n--) {
    cin >> cx >> cy;
    a = P(ax, ay); b = P(bx, by); c = P(cx, cy);
    P p = project(a, b, c);
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  
  return 0;
}