#include <stdio.h>
#include <math.h>

struct point {
  double x;
  double y;
};

double distance(struct point p1, struct point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main(void) {
  struct point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}