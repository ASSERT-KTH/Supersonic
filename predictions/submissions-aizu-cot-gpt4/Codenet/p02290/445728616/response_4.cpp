#include <complex>
#include <cstdio>
using namespace std;

complex<double> project(complex<double> a, complex<double> b, complex<double> c) {
  return a + (b - a) * real((c - a) / (b - a));
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    complex<double> p = project(complex<double>(ax, ay), complex<double>(bx, by), complex<double>(cx, cy));
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  return 0;
}