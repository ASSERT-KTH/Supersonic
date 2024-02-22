#include <stdio.h>
#include <complex>

using namespace std;
typedef complex<double> P;
P project(P a, P b, P c) {
  return a + b * real(c / b);
}
int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  P a(ax, ay), b(bx - ax, by - ay), c;
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    c.real(cx - ax);
    c.imag(cy - ay);
    P p = project(a, b, c);
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}