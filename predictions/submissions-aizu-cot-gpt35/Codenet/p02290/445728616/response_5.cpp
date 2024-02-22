#include <iostream>
#include <iomanip>
#include <complex>

struct Point {
  double x;
  double y;
};

Point project(const Point& a, const Point& b, const Point& c) {
  Point ab = {b.x - a.x, b.y - a.y};
  Point ac = {c.x - a.x, c.y - a.y};
  double scale = (ac.x * ab.x + ac.y * ab.y) / (ab.x * ab.x + ab.y * ab.y);
  return {a.x + scale * ab.x, a.y + scale * ab.y};
}

int main() {
  double ax, ay, bx, by, cx, cy;
  size_t n;
  std::cin >> ax >> ay >> bx >> by >> n;
  
  while (n--) {
    std::cin >> cx >> cy;
    Point p = project({ax, ay}, {bx, by}, {cx, cy});
    std::cout << std::fixed << std::setprecision(8) << p.x << " " << p.y << "\n";
  }
  
  return 0;
}