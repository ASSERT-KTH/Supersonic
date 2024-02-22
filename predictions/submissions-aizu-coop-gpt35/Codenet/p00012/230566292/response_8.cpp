#include <algorithm>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;
static const double EPS = 1e-12;
static const double INF = 1e24;

struct Point {
  double x, y;
};

struct Line {
  Point a, b;
};

struct LineSeg {
  Point a, b;
};

struct Circle {
  Point p;
  double r;
};

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(const Point& a, const Point& b, const Point& c, double cross_prod, double dot_prod) {
  double cross = cross_prod;
  double dot = dot_prod;
  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) == EOF)
    return true;
  Point A{x, y};
  scanf("%lf %lf", &x, &y);
  Point B{x, y};
  scanf("%lf %lf", &x, &y);
  Point C{x, y};
  scanf("%lf %lf", &x, &y);
  Point P{x, y};
  double cross_prod = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
  double dot_prod = (B.x - A.x) * (P.x - A.x) + (B.y - A.y) * (P.y - A.y);
  CCWiseState tmp = ccwise(A, P, B, cross_prod, dot_prod);
  if (tmp != ccwise(B, P, C, cross_prod, dot_prod)) {
    return !printf("NO\n");
  } else if (tmp != ccwise(C, P, A, cross_prod, dot_prod)) {
    return !printf("NO\n");
  }
  printf("YES\n");
  return false;
}

int main() {
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}