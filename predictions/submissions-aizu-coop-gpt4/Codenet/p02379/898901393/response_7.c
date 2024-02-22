#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

// Inline this function to eliminate the function call overhead
static inline double distance(const point* p1, const point* p2) {
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  return sqrt(dx*dx + dy*dy);
}

int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);

  // Pass the address of the points to the function to avoid copying the structs
  d = distance(&p1, &p2);

  printf("%.5f\n", d);
  return 0;
}