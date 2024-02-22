#include <cstdio>

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    double real = (bx - ax) * (dx - cx);
    double imag = (bx - ax) * (cy - dy);
    int result;
    if (imag == 0)
      result = 2;
    else if (real == 0)
      result = 1;
    else
      result = 0;

    printf("%d\n", result);
  }
  return 0;
}