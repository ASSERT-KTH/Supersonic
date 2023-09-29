#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

double distance(point p1, point p2) {
  double temp1, temp2, temp3;
  temp1 = p1.x - p2.x;
  temp2 = p1.y - p2.y;
  temp3 = temp1 * temp1 + temp2 * temp2;
  return sqrt(temp3);
}

int main(void) {
  point p1, p2;
  double d;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}