#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

inline double distance(const point* p1, const point* p2) {
  double x_diff = p1->x - p2->x;
  double y_diff = p1->y - p2->y;
  return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main(void) {
  point p1, p2;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  printf("%.5f\n", distance(&p1, &p2));
  return 0;
}