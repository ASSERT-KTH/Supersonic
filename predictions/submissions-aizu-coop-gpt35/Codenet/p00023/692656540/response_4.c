#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d_squared;
  int* ans;

  scanf("%d", &n);
  ans = (int*)malloc(sizeof(int) * n);

  for (k = 0; k < n; k++) {
    fscanf(stdin, "%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double x_diff_squared = (xb - xa) * (xb - xa);
    double y_diff_squared = (yb - ya) * (yb - ya);
    d_squared = x_diff_squared + y_diff_squared;

    if (d_squared > (ra + rb) * (ra + rb)) {
      ans[k] = 0;
    } else if (d_squared < (ra - rb) * (ra - rb)) {
      ans[k] = 2;
    } else if (d_squared < (rb - ra) * (rb - ra)) {
      ans[k] = -2;
    } else {
      ans[k] = 1;
    }
  }

  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }

  free(ans);

  return 0;
}