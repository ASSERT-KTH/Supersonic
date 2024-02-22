#include <stdio.h>

#define MAXN 1000  // Assuming maximum 'n' is 1000

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int ans[MAXN];
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = (xb - xa)*(xb - xa) + (yb - ya)*(yb - ya);  // Square of distance
    d[1] = (ra + rb)*(ra + rb);  // Square of sum of radii
    d[2] = (ra - rb)*(ra - rb);  // Square of difference of radii
    if (d[0] > d[1]) {
      ans[k] = 0;
    } else if (d[2] > d[0]) {
      ans[k] = 2;
    } else if (d[0] < d[2]) {
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