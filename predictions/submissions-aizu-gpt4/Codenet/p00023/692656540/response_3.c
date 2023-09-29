#include <math.h>
#include <stdio.h>
#include <vector>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0, d1, d2, d3;
  scanf("%d", &n);
  std::vector<int> ans(n);
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d0 = hypot(xb - xa, yb - ya);
    d1 = ra + rb;
    d2 = fabs(ra - rb);
    if (d0 > d1) {
      ans[k] = 0;
    } else if (d2 > d0) {
      ans[k] = (ra > rb) ? 2 : -2;
    } else {
      ans[k] = 1;
    }
  }
  for (int result : ans) {
    printf("%d\n", result);
  }
  return 0;
}