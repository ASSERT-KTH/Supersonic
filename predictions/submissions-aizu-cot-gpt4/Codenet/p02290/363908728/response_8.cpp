#include <iostream>
#include <vector>
#include <complex>

struct CWW {
  CWW() {
    std::cout << std::fixed << std::setprecision(15);
  }
} STAR;

using D = double;
using Point = std::complex<D>;

struct Segment {
  Point p1, p2;
  Segment(const Point &p1 = Point(), const Point &p2 = Point())
      : p1(p1), p2(p2) {}
};

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

struct Circle {
  Point c;
  D r;
  Circle(const Point &c = Point(), const D &r = 0.0) : c(c), r(r) {}
};

using Polygon = std::vector<Point>;

D dot(const Point &a, const Point &b) {
  return std::real(a) * std::real(b) + std::imag(a) * std::imag(b);
}

D cross(const Point &a, const Point &b) {
  return std::real(a) * std::imag(b) - std::imag(a) * std::real(b);
}

Point projection(const Point &a, const Point &b) { return a * std::real(b / a); }

int main() {
  Line L;
  D x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  L = Line(Point(x1, y1), Point(x2, y2));
  
  int Q;
  std::cin >> Q;
  while (Q--) {
    D px, py;
    std::cin >> px >> py;
    Point p(px, py);
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    std::cout << std::real(w) << " " << std::imag(w) << std::endl;
  }
  return 0;
}