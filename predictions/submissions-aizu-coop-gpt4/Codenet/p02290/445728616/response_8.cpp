#include <iostream>
#include <complex>

using namespace std;

typedef complex<double> P;

double ax, ay, bx, by, cx, cy;
int n;

P project(P a, P b, P c) {
  b -= a, c -= a;
  double realPart = real(c / b);
  return a + b * realPart;
}

int main() {
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);

  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    P p = project(P(ax, ay), P(bx, by), P(cx, cy));
    printf("%.8f %.8f\n", p.real(), p.imag());
  }

  return 0;
}
