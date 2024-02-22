#include <stdio.h>
#define MAX_N 1000
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[3];
  scanf("%d", &n);
  int ans[MAX_N], *pans = ans;
  for (k = 0; k < n; k++, pans++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d[1] = (ra + rb) * (ra + rb);
    d[2] = (ra - rb) * (ra - rb);
    if (d[0] > d[1]) {
      *pans = 0;
    } else if (d[2] > d[0]) {
      *pans = 2;
    } else if (d[0] < d[2]) {
      *pans = -2;
    } else {
      *pans = 1;
    }
  }
  for (k = 0, pans = ans; k < n; k++, pans++) {
    printf("%d\n", *pans);
  }
  return 0;
}