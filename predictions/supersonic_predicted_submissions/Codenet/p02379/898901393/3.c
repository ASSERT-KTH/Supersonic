#include <math.h>
#include <stdio.h>
typedef struct point {
  double x;
  double y;
} point;
int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}
