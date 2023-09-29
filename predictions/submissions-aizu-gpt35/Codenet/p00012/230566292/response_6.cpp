#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
static const double EPS = 1e-12;
static const double INF = 1e24;
const double PI = acos(-1.0);
using Point = pair<double, double>;
using Plane = vector<Point>;
bool operator<(const Point &a, const Point &b) {
  return a.first != b.first ? a.first < b.first : a.second < b.second;
}
double cross_prod(const Point &a, const Point &b) { return a.first * b.second - a.second * b.first; }
double dot_prod(const Point &a, const Point &b) { return a.first * b.first + a.second * b.second; }
struct Line : public pair<Point, Point> {
  Line() {}
  Line(const Point &a, const Point &b) {
    first = a;
    second = b;
  }
};
struct LineSeg : public pair<Point, Point> {
  LineSeg() {}
  LineSeg(const Point &a, const Point &b) {
    first = a;
    second = b;
  }
};
struct Circle {
  Point p;
  double r;
  Circle() {}
  Circle(const Point &p, const double r) : p(p), r(r) {}
};
int ccwise(Point a, Point b, Point c) {
  b.first -= a.first;
  b.second -= a.second;
  c.first -= a.first;
  c.second -= a.second;
  double cross = cross_prod(b, c);
  if (cross > EPS) {
    return 1;
  } else if (cross < -EPS) {
    return -1;
  } else if (dot_prod(b, c) < -EPS) {
    return 2;
  } else if (abs(b) < abs(c)) {
    return -2;
  } else {
    return 0;
  }
}
bool testcase_ends() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) == EOF)
    return 1;
  Point A(x, y);
  scanf("%lf %lf", &x, &y);
  Point B(x, y);
  scanf("%lf %lf", &x, &y);
  Point C(x, y);
  scanf("%lf %lf", &x, &y);
  Point P(x, y);
  int tmp = ccwise(A, P, B);
  if (tmp != ccwise(B, P, C)) {
    return !printf("NO\n");
  } else if (tmp != ccwise(C, P, A)) {
    return !printf("NO\n");
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
