#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} point;

inline double distance(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double fast_read_double() {
  double result = 0.0, div = 1.0;
  char c = getchar_unlocked();
  while (c < '0' || c > '9') c = getchar_unlocked();
  while (c >= '0' && c <= '9') {
    result = result * 10 + (c - '0');
    c = getchar_unlocked();
  }
  if (c == '.') {
    c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
      result = result + (c - '0') / div;
      div *= 10.0;
      c = getchar_unlocked();
    }
  }
  return result;
}

int main(void) {
  point p1, p2;
  double d;
  p1.x = fast_read_double(); p1.y = fast_read_double();
  p2.x = fast_read_double(); p2.y = fast_read_double();
  d = distance(p1, p2);
  printf("%.5f\n", d);
  return 0;
}