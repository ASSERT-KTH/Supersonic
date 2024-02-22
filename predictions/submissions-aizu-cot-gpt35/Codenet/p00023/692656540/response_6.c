#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int ans[1000];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d[2] = ra - rb;
    d[3] = rb - ra;
    if (d[0] > ra + rb) {
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
  return 0;
}