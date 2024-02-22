#include <cstdio>

struct Point {
  double x, y;

  Point operator-(const Point &p) const {
    return {x - p.x, y - p.y};
  }

  Point operator*(double scalar) const {
    return {x * scalar, y * scalar};
  }

  Point operator+(const Point &p) const {
    return {x + p.x, y + p.y};
  }

  double dot(const Point &p) const {
    return x * p.x + y * p.y;
  }

  double norm() const {
    return x * x + y * y;
  }
};

Point project(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;
  double t = c.dot(b) / b.norm();
  return a + b * t;
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    Point p = project({ax, ay}, {bx, by}, {cx, cy});
    printf("%.8f %.8f\n", p.x, p.y);
  }
  return 0;
}