#include <stdio.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  
  scanf("%d", &n);
  
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    
    double d = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    
    if (d > ra + rb) {
      printf("0\n");
    } else if (ra > d + rb) {
      printf("2\n");
    } else if (rb > d + ra) {
      printf("-2\n");
    } else {
      printf("1\n");
    }
  }
  
  return 0;
}