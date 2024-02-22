#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d, d1, d2, d3;
  scanf("%d", &n);
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d1 = (ra + rb) * (ra + rb);
    d2 = (ra - rb) * (ra - rb);
    d3 = (rb - ra) * (rb - ra);
    if (d > d1) {
      printf("%d\n", 0);
    } else if (d < d2) {
      printf("%d\n", 2);
    } else if (d < d3) {
      printf("%d\n", -2);
    } else {
      printf("%d\n", 1);
    }
  }
  return 0;
}