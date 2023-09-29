#include <math.h>
#include <stdio.h>
typedef struct point {
  double x;
  double y;
} point;
double distance(point p1, point p2) {
  double temp;
  temp = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  return sqrt(temp);
}
int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1, &p1, &p2, &p2);
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}