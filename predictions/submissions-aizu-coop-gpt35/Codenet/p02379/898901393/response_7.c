#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

double sqrt(double x); // Function prototype for sqrt()

double distance(const point* p1, const point* p2) {
  double temp = (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
  return sqrt(temp);
}

int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(&p1, &p2);
  printf("%.5f\n", d);
  return 0;
}