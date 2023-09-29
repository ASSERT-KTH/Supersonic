#include <math.h>
#include <stdio.h>
typedef struct point {
  double x;
  double y;
} point;

double squared_distance(point p1, point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double distance(point p1, point p2) {
  return sqrt(squared_distance(p1, p2));
}

int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}