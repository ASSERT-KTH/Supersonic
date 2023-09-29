#include <stdio.h>
int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d, sum, diff;
  scanf("%d", &n);
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d = (xb - xa)*(xb - xa) + (yb - ya)*(yb - ya);
    sum = (ra + rb)*(ra + rb);
    diff = (ra - rb)*(ra - rb);

    if (d > sum) {
      printf("0\n");
    } else if (d > diff) {
      printf("1\n");
    } else if (d == diff) {
      printf("2\n");
    } else {
      printf("-2\n");
    }
  }
  return 0;
}