#include <float.h>
#include <math.h>
#include <stdio.h>
#define MAX_N 100001
int main() {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d1, d2, d3, d4;
  int ans[MAX_N];
  scanf("%d", &n);
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d1 = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    d2 = ra + rb;
    d3 = ra - rb;
    d4 = rb - ra;
    if (d1 > d2) {
      ans[k] = 0;
    } else if (d1 < d3 && d1 > d4) {
      ans[k] = 2;
    } else if (d1 < d4 && d1 > d3) {
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