#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d, sum, diff1, diff2;
  scanf("%d", &n);
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya); // Square of distance
    sum = (ra + rb) * (ra + rb); // Square of sum of radii
    diff1 = (ra - rb) * (ra - rb); // Square of difference of radii (ra>rb)
    diff2 = (rb - ra) * (rb - ra); // Square of difference of radii (rb>ra)

    if (d > sum) {
      printf("%d\n", 0);
    } else if (diff1 > d) {
      printf("%d\n", 2);
    } else if (diff2 > d) {
      printf("%d\n", -2);
    } else {
      printf("%d\n", 1);
    }
  }
  return 0;
}