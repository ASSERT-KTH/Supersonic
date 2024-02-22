#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

double distance(const point* p1, const point* p2) {
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  return sqrt(dx * dx + dy * dy);
}

int main(void) {
  point p1, p2;
  char input[100];
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  double d = distance(&p1, &p2);
  char output[20];
  sprintf(output, "%.5f\n", d);
  puts(output);
  return 0;
}