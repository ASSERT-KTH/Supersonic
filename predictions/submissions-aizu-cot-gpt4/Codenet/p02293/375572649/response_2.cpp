#include <stdio.h>

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    double k1 = (bx - ax)*(dx - cx);
    double k2 = (by - ay)*(cy - dy);
    if (k2 == 0)
      puts("2");
    else if (k1 == 0)
      puts("1");
    else
      puts("0");
  }
  return 0;
}