#include <iostream>
#include <iomanip>

struct Point {
  double x, y;
};

Point project(const Point& a, const Point& b, const Point& c) {
  double bx = b.x - a.x;
  double by = b.y - a.y;
  double cx = c.x - a.x;
  double cy = c.y - a.y;
  double dot = bx * cx + by * cy;
  double lenSq = bx * bx + by * by;
  double t = dot / lenSq;
  return {a.x + t * bx, a.y + t * by};
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  std::cin >> ax >> ay >> bx >> by >> n;

  Point a = {ax, ay};
  Point b = {bx, by};

  while (n--) {
    std::cin >> cx >> cy;
    Point c = {cx, cy};
    Point p = project(a, b, c);
    std::cout << std::fixed << std::setprecision(8) << p.x << " " << p.y << "\n";
  }

  return 0;
}