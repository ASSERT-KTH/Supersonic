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
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}