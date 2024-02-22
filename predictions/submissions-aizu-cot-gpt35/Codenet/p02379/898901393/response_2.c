#include <stdio.h>

struct point {
  double x;
  double y;
};

double distance(struct point p1, struct point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main(void) {
  struct point p1, p2;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  printf("%.5f\n", distance(p1, p2));
  return 0;
}