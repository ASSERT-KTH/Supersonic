#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

int main(void) {
  point p1, p2;
  double dx, dy;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  dx = p1.x - p2.x;
  dy = p1.y - p2.y;
  printf("%.5f\n", sqrt(dx * dx + dy * dy));
  return 0;
}