#include <float.h>
#include <math.h>
#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int ans[n];
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = hypot(xb - xa, yb - ya);
    d[1] = ra + rb;
    d[2] = fabs(ra - rb);
    d[3] = fabs(rb - ra);
    if (d[0] > d[1]) {
      ans[k] = 0;
    } else if (d[2] > d[0]) {
      ans[k] = 2;
    } else if (d[3] > d[0]) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }
  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }
  return 0;
}