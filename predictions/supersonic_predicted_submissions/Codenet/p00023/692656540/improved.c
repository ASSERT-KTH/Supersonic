#include <float.h>
#include <math.h>
#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int ans[n];
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = sqrt(pow(xb - xa, 2.0) + pow(yb - ya, 2.0));
    d[1] = ra + rb;
    d[2] = ra - rb;
    d[3] = rb - ra;
    if (d[0] > d[1]) {
      printf("0\n");
    } else if (d[2] > d[0]) {
      printf("2\n");
    } else if (d[3] > d[0]) {
      printf("-2\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}
