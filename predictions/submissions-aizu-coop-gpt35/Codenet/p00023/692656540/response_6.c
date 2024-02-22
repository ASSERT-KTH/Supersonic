#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double maxDistance;

  scanf("%d", &n);
  int ans[n];

  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double distance = sqrt(pow(xb - xa, 2.0) + pow(yb - ya, 2.0));
    maxDistance = fmax(ra + rb, distance);
    maxDistance = fmax(maxDistance, ra - rb);
    maxDistance = fmax(maxDistance, rb - ra);

    if (distance > maxDistance) {
      ans[k] = 0;
    } else if (ra - rb > distance) {
      ans[k] = 2;
    } else if (rb - ra > distance) {
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