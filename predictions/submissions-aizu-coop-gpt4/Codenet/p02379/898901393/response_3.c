#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

// Suggest the compiler to inline the function
inline double distance(point p1, point p2) {
  // Return the result of the computation directly
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main(void) {
  point p1, p2;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  // The distance function might be inlined here, depending on the compiler's decision
  double d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}