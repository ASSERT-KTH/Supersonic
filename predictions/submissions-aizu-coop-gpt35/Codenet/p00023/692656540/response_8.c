#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  scanf("%d", &n);
  int* ans = (int*)malloc(n * sizeof(int)); // Use dynamic allocation for ans

  // Calculate d[1] outside the loop
  scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
  d[1] = ra + rb;

  for (k = 0; k < n; k++) {
    d[0] = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya); // Avoid pow and sqrt
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

  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }

  free(ans); // Free dynamically allocated memory
  return 0;
}