#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);
  
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double d = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double sum_r = ra + rb;
    double diff_r = ra - rb;
    double diff_rb = rb - ra;
    if (d > sum_r * sum_r) {
      printf("0\n");
    } else if (diff_r > d) {
      printf("2\n");
    } else if (diff_rb > d) {
      printf("-2\n");
    } else {
      printf("1\n");
    }
  }
  
  return 0;
}