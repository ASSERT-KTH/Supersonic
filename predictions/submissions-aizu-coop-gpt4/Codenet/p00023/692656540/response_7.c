#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d0, d1, d2, d3;
  char buffer[16];

  scanf("%d", &n);
  int* ans = (int*)malloc(sizeof(int) * n);
  if (!ans) {
    return 1;  // malloc failed
  }

  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d0 = sqrt((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya));
    d1 = ra + rb;

    if (d0 > d1) {
      ans[k] = 0;
    } else {
      d2 = ra - rb;
      d3 = rb - ra;
      if (d2 > d0) {
        ans[k] = 2;
      } else if (d3 > d0) {
        ans[k] = -2;
      } else {
        ans[k] = 1;
      }
    }
  }

  for (k = 0; k < n; k++) {
    sprintf(buffer, "%d", ans[k]);
    puts(buffer);
  }

  free(ans);
  return 0;
}