#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d;
  scanf("%d", &n);
  int ans[n];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);  // Squaring the distance
    ra *= ra;  // Squaring the radii
    rb *= rb;
    if (d > (ra + rb)) {
      ans[k - 1] = 0;
    } else if (ra > (d + rb)) {
      ans[k - 1] = 2;
    } else if (rb > (d + ra)) {
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