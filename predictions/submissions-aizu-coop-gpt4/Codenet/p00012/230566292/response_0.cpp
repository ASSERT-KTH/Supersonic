#include <cstdio>
#include <cmath>

struct Point {
  double x, y;
};

double cross_prod(Point a, Point b) { return a.x*b.y - a.y*b.x; }
double dot_prod(Point a, Point b) { return a.x*b.x + a.y*b.y; }

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(Point a, Point b, Point c) {
  b.x -= a.x; b.y -= a.y;
  c.x -= a.x; c.y -= a.y;
  
  double cross = cross_prod(b, c);
  double dot = dot_prod(b, c);
  double norm_b = b.x*b.x + b.y*b.y;
  double norm_c = c.x*c.x + c.y*c.y;

  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (norm_b < norm_c) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

int testcase_ends() {
  Point A, B, C, P;

  if (scanf("%lf %lf", &A.x, &A.y) == EOF)
    return 1;
  scanf("%lf %lf", &B.x, &B.y);
  scanf("%lf %lf", &C.x, &C.y);
  scanf("%lf %lf", &P.x, &P.y);

  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C)) {
    printf("NO\n");
    return 1;
  } else if (tmp != ccwise(C, P, A)) {
    printf("NO\n");
    return 1;
  }
  printf("YES\n");
  return 0;
}

int main() {
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}