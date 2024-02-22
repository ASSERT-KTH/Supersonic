#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d, sum, diff_ra_rb, diff_rb_ra;
  scanf("%d", &n);
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya); // square of distance
    sum = (ra + rb) * (ra + rb); // square of sum of radii
    diff_ra_rb = (ra - rb) * (ra - rb); // square of difference of radii
    diff_rb_ra = (rb - ra) * (rb - ra); // square of difference of radii
    if (d > sum) {
      printf("0\n");
    } else if (diff_ra_rb > d) {
      printf("2\n");
    } else if (diff_rb_ra > d) {
      printf("-2\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}