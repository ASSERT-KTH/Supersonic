#include <iostream>
#include <cstdio>
using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator-=(const Point& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  double dot(const Point& rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  Point operator*(double rhs) const {
    return Point(x * rhs, y * rhs);
  }
};

Point project(Point a, Point b, Point c) {
  b -= a, c -= a;
  double factor = c.dot(b) / b.dot(b);
  return a + b * factor;
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  Point a(ax, ay), b(bx, by);
  while (n--) {
    cin >> cx >> cy;
    Point c(cx, cy);
    Point p = project(a, b, c);
    printf("%.8f %.8f\n", p.x, p.y);
  }
  return 0;
}