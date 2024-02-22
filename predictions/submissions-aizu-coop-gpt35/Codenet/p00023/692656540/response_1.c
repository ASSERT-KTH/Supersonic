#include <stdio.h>

// Declare sqrt() function prototype
double sqrt(double x);

int main(void) {
  int k, n;
  double xa, ya, ra, xb, yb, rb;
  
  // Remove unnecessary inclusion of math.h
  
  scanf("%d", &n);
  
  // Use a fixed-size array instead of variable-length array
  int ans[1000]; // Assuming 1000 as the maximum value of n
  
  for (k = 1; k <= n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    
    // Calculate the square of the distance
    double dx = xb - xa;
    double dy = yb - ya;
    double d_squared = dx * dx + dy * dy;
    
    double sum_of_radii = ra + rb;
    double diff_of_radii = ra - rb;
    
    // Simplify conditions
    if (d_squared > sum_of_radii * sum_of_radii) {
      ans[k - 1] = 0;
    } else if (d_squared < diff_of_radii * diff_of_radii) {
      ans[k - 1] = -2;
    } else if (d_squared < 0.00001) {
      ans[k - 1] = 1;
    } else {
      ans[k - 1] = 2;
    }
  }
  
  for (k = 1; k <= n; k++) {
    printf("%d\n", ans[k - 1]);
  }
  
  return 0;
}