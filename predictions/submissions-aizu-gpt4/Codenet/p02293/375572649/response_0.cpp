#include <cstdio>
#include <complex>
using namespace std;
typedef complex<double> P;
int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    P k = P(bx - ax, by - ay) * P(dx - cx, dy - cy);
    if (abs(k.imag()) < 1e-10)
      printf("2\n");
    else if (abs(k.real()) < 1e-10)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}