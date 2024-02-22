#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[2];
  scanf("%d", &n);
  int *ans = (int*) malloc(n * sizeof(int));
  for (k = 0; k < n; ++k) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d[1] = (ra + rb) * (ra + rb);
    double raMinusRb = (ra - rb) * (ra - rb);
    double rbMinusRa = (rb - ra) * (rb - ra);
    if (d[0] > d[1]) {
      ans[k] = 0;
    } else if (raMinusRb > d[0]) {
      ans[k] = 2;
    } else if (rbMinusRa > d[0]) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }
  for (k = 0; k < n; ++k) {
    printf("%d\n", ans[k]);
  }
  free(ans);
  return 0;
}