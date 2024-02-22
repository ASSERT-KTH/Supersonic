#include <stdio.h>
#include <math.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  int ans;

  scanf("%d", &n);
  int ans[n];

  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dx = xb - xa;
    double dy = yb - ya;
    double dist_squared = dx * dx + dy * dy;
    double ra_plus_rb = ra + rb;
    double ra_minus_rb = ra - rb;
    double rb_minus_ra = rb - ra;

    if (dist_squared > ra_plus_rb * ra_plus_rb) {
      ans = 0;
    } else if (ra_minus_rb * ra_minus_rb > dist_squared) {
      ans = 2;
    } else if (rb_minus_ra * rb_minus_ra > dist_squared) {
      ans = -2;
    } else {
      ans = 1;
    }

    ans[k] = ans;
  }

  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }

  return 0;
}