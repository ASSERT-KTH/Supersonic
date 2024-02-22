#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator- (const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  Point operator* (double a) const {
    return Point(x * a, y * a);
  }
};

double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

double norm(const Point &p) {
  return p.x * p.x + p.y * p.y;
}

Point project(const Point &a, const Point &b, const Point &c) {
  Point base = b - a;
  double r = dot(c - a, base) / norm(base);
  return a + base * r;
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf%lf%lf%lf%d", &ax, &ay, &bx, &by, &n);
  Point a(ax, ay), b(bx, by);
  while (n--) {
    scanf("%lf%lf", &cx, &cy);
    Point c(cx, cy);
    Point p = project(a, b, c);
    printf("%.8f %.8f\n", p.x, p.y);
  }
  return 0;
}