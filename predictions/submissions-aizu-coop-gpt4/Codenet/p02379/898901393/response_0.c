#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

// Passing structs by reference to avoid copying
double distance(point* p1, point* p2) {
  double temp;
  temp = (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
  return temp; // Returning square of the distance
}

int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(&p1, &p2); // Passing struct addresses
  printf("%.5f\n", d);
  return 0;
}