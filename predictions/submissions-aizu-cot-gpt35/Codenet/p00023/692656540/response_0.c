#include <float.h>
#include <math.h>
#include <stdio.h>

#define MAX_N 10000

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int ans[MAX_N];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dx = xb - xa;
    double dy = yb - ya;
    double distance_squared = dx * dx + dy * dy;
    d[0] = sqrt(distance_squared);
    d[1] = ra + rb;
    d[2] = ra - rb;
    d[3] = rb - ra;
    ans[k - 1] = (fabs(d[2]) > d[0]) ? 2 : (fabs(d[3]) > d[0]) ? -2 : (d[0] > d[1]) ? 0 : 1;
  }
  for (k = 1; k <= n; k++) {
    printf("%d\n", ans[k - 1]);
  }
  return 0;
}