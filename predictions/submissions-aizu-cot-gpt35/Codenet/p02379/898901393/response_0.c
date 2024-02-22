#include <stdio.h>

typedef struct {
  double x;
  double y;
} point;

double distance(const point* p1, const point* p2) {
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  double temp = dx * dx + dy * dy;
  return sqrt(temp);
}

int main(void) {
  point p1, p2;
  double d;
  fscanf(stdin, "%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(&p1, &p2);
  printf("%.5f\n", d);
  return 0;
}