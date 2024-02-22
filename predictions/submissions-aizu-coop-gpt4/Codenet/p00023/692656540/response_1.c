#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double d0 = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    double d1 = ra + rb;
    int ans = 1;
    if (d0 > d1) {
      ans = 0;
    } else {
      double d2 = ra - rb;
      double d3 = rb - ra;
      if (d2 > d0) {
        ans = 2;
      } else if (d3 > d0) {
        ans = -2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}