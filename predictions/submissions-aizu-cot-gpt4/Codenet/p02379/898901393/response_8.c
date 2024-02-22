#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

int main(void) {
  point p1, p2;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);

  double temp = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  printf("%.5f\n", sqrt(temp));

  return 0;
}