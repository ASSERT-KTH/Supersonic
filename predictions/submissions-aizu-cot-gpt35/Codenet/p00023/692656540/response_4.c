#include <math.h>
#include <stdio.h>

int main(void) {
  int k, n;
  double x1, y1, r1, x2, y2, r2;
  double d[4];
  
  scanf("%d", &n);
  
  int ans[n];
  
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    d[0] = dx * dx + dy * dy;
    d[1] = (r1 + r2) * (r1 + r2);
    d[2] = (r1 - r2) * (r1 - r2);
    d[3] = (r2 - r1) * (r2 - r1);
    
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
  
  return 0;
}