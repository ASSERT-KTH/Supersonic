#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0, d1, d2, d3;
  scanf("%d", &n);
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d0 = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d1 = (ra + rb) * (ra + rb);
    if (d0 > d1) {
      printf("0\n");
    } else {
      d2 = (ra - rb) * (ra - rb);
      if (d2 > d0) {
        printf("2\n");
      } else {
        d3 = (rb - ra) * (rb - ra);
        if (d3 > d0) {
          printf("-2\n");
        } else {
          printf("1\n");
        }
      }
    }
  }
  return 0;
}