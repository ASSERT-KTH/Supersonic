#include <cstdio>
#include <complex>
typedef std::complex<double> P;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  std::scanf("%d", &n);
  while (n--) {
    std::scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    P k = P(bx - ax, by - ay) * P(dx - cx, dy - cy);
    double real = k.real();
    double imag = k.imag();
    if (imag == 0)
      std::printf("2\n");
    else if (real == 0)
      std::printf("1\n");
    else
      std::printf("0\n");
  }
  return 0;
}