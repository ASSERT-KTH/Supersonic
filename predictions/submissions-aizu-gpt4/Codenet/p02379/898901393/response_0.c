#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

inline double distance(const point& p1, const point& p2) noexcept {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  point p1, p2;
  double d;
  if (scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y) != 4)
    return 1;
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}