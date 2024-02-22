#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];

  scanf("%d", &n);

  int ans[n]; // Fixed-size array for results

  for (k = 0; k < n; k++) { // Loop optimization: start from 0
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);

    double distance_squared = pow(xb - xa, 2.0) + pow(yb - ya, 2.0); // Avoid redundant computation
    double distance = sqrt(distance_squared); // Store the calculated distance

    d[0] = distance;
    d[1] = ra + rb;
    d[2] = ra - rb;
    d[3] = rb - ra;

    if (d[0] > d[1]) {
      ans[k] = 0;
    } else if (d[2] > d[0]) {
      ans[k] = 2;
    } else if (d[3] > d[0]) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }

  for (k = 0; k < n; k++) { // Loop optimization: start from 0
    printf("%d\n", ans[k]);
  }

  return 0;
}