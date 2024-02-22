#include <stdio.h>

int main(void) {
  int i, n;
  double xa, ya, ra, xb, yb, rb;
  double d[4];
  
  scanf("%d", &n);
  int ans[10000];
  
  for (i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    d[0] = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    d[1] = ra + rb;
    d[2] = ra - rb;
    d[3] = rb - ra;
    
    if (d[0] > d[1]) {
      ans[i] = 0;
    } else if (d[2] > d[0]) {
      ans[i] = 2;
    } else if (d[3] > d[0]) {
      ans[i] = -2;
    } else {
      ans[i] = 1;
    }
  }
  
  for (i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }
  
  return 0;
}