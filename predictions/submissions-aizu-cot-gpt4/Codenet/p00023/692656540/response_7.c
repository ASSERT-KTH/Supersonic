#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0_squared, d1_squared, d2_squared, d3_squared;
  scanf("%d", &n);
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d0_squared = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d1_squared = (ra + rb) * (ra + rb);
    d2_squared = (ra - rb) * (ra - rb);
    d3_squared = (rb - ra) * (rb - ra);
    if (d0_squared > d1_squared) {
      printf("0\n");
    } else if (d2_squared > d0_squared) {
      printf("2\n");
    } else if (d3_squared > d0_squared) {
      printf("-2\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}