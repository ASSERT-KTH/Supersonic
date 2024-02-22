#include <cstdio> // to use scanf and printf
#include <complex> // to use complex numbers

int main() {
  
  // make C++ input/output operations faster
  ios_base::sync_with_stdio(false);
  
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  
  // use double instead of complex<double> for memory efficiency
  double real_part, imag_part;
  
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    real_part = (bx - ax) * (dx - cx);
    imag_part = (by - ay) * (cy - dy);
    
    // store the real and imaginary parts in variables to reduce function calls
    if (imag_part == 0)
      printf("2\n");
    else if (real_part == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  
  return 0;
}