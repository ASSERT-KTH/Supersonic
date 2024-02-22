#include <math.h>
#include <stdio.h>
typedef struct point {
  float x;
  float y;
} point;
float distance(const point* p1, const point* p2) {
  float temp;
  temp = (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
  return sqrt(temp);
}
int main(void) {
  point p1, p2;
  float d;
  scanf("%f%f%f%f", &p1.x, &p1.y, &p2.x, &p2.y);
  d = distance(&p1, &p2);
  printf("%.5f\n", d);
  return 0;
}