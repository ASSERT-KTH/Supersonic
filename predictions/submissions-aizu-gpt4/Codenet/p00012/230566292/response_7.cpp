#include <cstdio>
using namespace std;
static const double EPS = 1e-12;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};
double cross_prod(const Point &a, const Point &b) { 
    return a.x * b.y - a.y * b.x; 
}
double dot_prod(const Point &a, const Point &b) { 
    return a.x * b.x + a.y * b.y; 
}
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
  if (cross_prod(b, c) > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross_prod(b, c) < 0) {
    return CLOCKWISE;
  } else if (dot_prod(b, c) < 0) {
    return ONLINE_BACK;
  } else if (b.x * b.x + b.y * b.y < c.x * c.x + c.y * c.y) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}
bool testcase_ends() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) == EOF)
    return true;
  Point A(x, y);
  scanf("%lf %lf", &x, &y);
  Point B(x, y);
  scanf("%lf %lf", &x, &y);
  Point C(x, y);
  scanf("%lf %lf", &x, &y);
  Point P(x, y);
  CCWiseState tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
    printf("NO\n");
    return false;
  }
  printf("YES\n");
  return false;
}
int main() {
  while (!testcase_ends()) {}
  return 0;
}