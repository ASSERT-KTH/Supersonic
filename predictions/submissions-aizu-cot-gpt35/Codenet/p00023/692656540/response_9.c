#include <stdio.h>
#include <math.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);
  int ans[n];
  
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dx = xb - xa;
    double dy = yb - ya;
    double d_squared = dx * dx + dy * dy;
    double r_sum = ra + rb;
    double r_diff = ra - rb;

    if (d_squared > r_sum * r_sum) {
      ans[k] = 0;
    } else if (r_diff * r_diff > d_squared) {
      ans[k] = 2;
    } else if (r_diff * r_diff == d_squared && d_squared != 0) {
      ans[k] = 1;
    } else {
      ans[k] = -2;
    }
  }

  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }
  
  return 0;
}