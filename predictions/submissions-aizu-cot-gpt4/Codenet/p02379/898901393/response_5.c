#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

double distance(const point *p1, const point *p2) { // pass by reference
  double dx = p1->x - p2->x; // calculate difference once
  double dy = p1->y - p2->y; // calculate difference once
  return sqrt(pow(dx, 2) + pow(dy, 2)); // use pow function
}

int main(void) {
  point p1, p2;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  double d = distance(&p1, &p2); // pass by reference
  printf("%.5f\n", d);
  return 0;
}