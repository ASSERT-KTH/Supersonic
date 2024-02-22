#include <cstdio>

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    double real = (bx - ax) * (dx - cx);
    double imag = (by - ay) * (cy - dy);
    if (real == 0)
      printf("2\n");
    else if (imag == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}