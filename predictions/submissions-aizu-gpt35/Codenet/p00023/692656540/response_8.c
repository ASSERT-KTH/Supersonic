#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d1, d2, d3, d4;
  scanf("%d", &n);
  int ans[n];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d1 = sqrt(pow(xb - xa, 2.0) + pow(yb - ya, 2.0));
    d2 = ra + rb;
    d3 = ra - rb;
    d4 = rb - ra;
    if (d1 > d2) {
      ans[k - 1] = 0;
    } else if (d3 > d1) {
      ans[k - 1] = 2;
    } else if (d4 > d1) {
      ans[k - 1] = -2;
    } else {
      ans[k - 1] = 1;
    }
  }
  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }
  return 0;
}