#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int ans[100]; // Assuming a maximum value of n as 100

  for (int k = 0; k < n; k++) {
    double xa, ya, ra, xb, yb, rb;
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    
    double d0 = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double d1 = ra + rb;
    double d2 = ra - rb;
    double d3 = rb - ra;

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

  for (int k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }

  return 0;
}