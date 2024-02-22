#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0, d1, d2, d3;
  scanf("%d", &n);
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d0 = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    d1 = ra + rb;
    d2 = ra - rb;
    d3 = rb - ra;
    if (d0 > d1) {
      printf("%d\n", 0);
    } else if (d2 > d0) {
      printf("%d\n", 2);
    } else if (d3 > d0) {
      printf("%d\n", -2);
    } else {
      printf("%d\n", 1);
    }
  }
  return 0;
}