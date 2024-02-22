#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);
  int ans[n];
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dx = xb - xa;
    double dy = yb - ya;
    double d = dx * dx + dy * dy;
    double rsum = ra + rb;
    double rdiff = ra - rb;
    if (d > rsum * rsum) {
      ans[k] = 0;
    } else if (rdiff * rdiff > d) {
      ans[k] = 2;
    } else if (rdiff * rdiff > -d) {
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