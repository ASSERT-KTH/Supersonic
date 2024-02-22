#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0, d1, d2, d3;

  scanf("%d", &n);
  int *ans = malloc(n * sizeof(int));

  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);

    double dx = xb - xa;
    double dy = yb - ya;

    d0 = dx * dx + dy * dy;
    d1 = ra + rb;
    d2 = ra - rb;
    d3 = rb - ra;

    if (d0 > d1) {
      ans[k] = 0;
    } else if (d2 > d0) {
      ans[k] = 2;
    } else if (d3 > d0) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }

  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }

  free(ans);
  return 0;
}