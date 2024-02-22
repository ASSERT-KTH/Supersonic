#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d, sum_radius, diff_radius;

  scanf("%d", &n);

  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);

    // Calculate the distance between centers of circles
    d = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));

    // Calculate the sum and difference of the radii
    sum_radius = ra + rb;
    diff_radius = fabs(ra - rb);

    // Compare and print the result
    if (d > sum_radius) {
      printf("0\n");
    } else if (diff_radius > d) {
      printf("%d\n", (ra > rb) ? 2 : -2);
    } else {
      printf("1\n");
    }
  }

  return 0;
}