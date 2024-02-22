#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  double x, y;
};

Point project(Point a, Point b, Point c) {
  b.x -= a.x, b.y -= a.y, c.x -= a.x, c.y -= a.y;
  double t = (c.x*b.x + c.y*b.y) / (b.x*b.x + b.y*b.y);
  return {a.x + t*b.x, a.y + t*b.y};
}

int main() {
  int n;
  Point a, b, c;
  scanf("%lf %lf %lf %lf %d", &a.x, &a.y, &b.x, &b.y, &n);
  while (n--) {
    scanf("%lf %lf", &c.x, &c.y);
    Point p = project(a, b, c);
    printf("%.8f %.8f\n", p.x, p.y);
  }
  return 0;
}