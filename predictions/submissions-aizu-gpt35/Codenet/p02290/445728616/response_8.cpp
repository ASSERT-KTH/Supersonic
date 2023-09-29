#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
P project(const P& a, const P& b, const P& c) {
  P b_ = b - a, c_ = c - a;
  return a + b_ * real(c_ / b_);
}
int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}