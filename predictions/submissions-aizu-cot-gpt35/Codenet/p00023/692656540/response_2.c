#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  double d[3];
  
  scanf("%d", &n);
  int ans[1000];
  
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    
    d[0] = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    d[1] = ra + rb;
    d[2] = ra - rb;
    
    if (d[0] > d[1]) {
      ans[k] = 0;
    } else if (d[2] > d[0]) {
      ans[k] = 2;
    } else {
      ans[k] = 1;
    }
    
    printf("%d\n", ans[k]);
  }
  
  return 0;
}