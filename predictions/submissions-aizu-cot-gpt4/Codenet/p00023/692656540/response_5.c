#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int *ans = new int[n];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double x_diff = xb - xa;
    double y_diff = yb - ya;
    d[0] = x_diff * x_diff + y_diff * y_diff;
    d[1] = (ra + rb) * (ra + rb);
    d[2] = (ra - rb) * (ra - rb);
    d[3] = (rb - ra) * (rb - ra);
    if (d[0] > d[1]) {
      ans[k - 1] = 0;
    } else if (d[2] > d[0]) {
      ans[k - 1] = 2;
    } else if (d[3] > d[0]) {
      ans[k - 1] = -2;
    } else {
      ans[k - 1] = 1;
    }
  }
  for (k = 1; k <= n; k++) {
    printf("%d\n", ans[k - 1]);
  }
  delete[] ans;
  return 0;
}