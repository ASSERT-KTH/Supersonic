#include <cstdio>
#include <complex>
typedef std::complex<double> P;
int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    P k = P(bx - ax, by - ay) * P(dx - cx, dy - cy);
    double imagK = k.imag();
    double realK = k.real();
    if (imagK == 0)
      printf("2\n");
    else if (realK == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}