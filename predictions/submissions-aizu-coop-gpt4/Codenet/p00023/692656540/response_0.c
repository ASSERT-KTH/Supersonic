#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  scanf("%d", &n);
  
  int* ans = (int*)malloc(n * sizeof(int)); // Dynamic memory allocation
  
  for (k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    
    double d0 = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)); // Replace pow with simple multiplication
    double d1 = ra + rb;
    double d2 = fabs(ra - rb); // Use fabs to find the absolute difference between ra and rb

    if (d0 > d1) {
      ans[k] = 0;
    } else if (d2 > d0) {
      ans[k] = (ra > rb) ? 2 : -2; // If ra is greater than rb, assign 2; otherwise, assign -2
    } else {
      ans[k] = 1;
    }
  }
  
  for (k = 0; k < n; k++) {
    printf("%d\n", ans[k]);
  }
  
  free(ans); // Free the dynamically allocated memory
  return 0;
}