#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

struct CWW {
  CWW() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    std::cout << std::fixed << std::setprecision(15);
  }
} STAR;

using D = double;
const D EPS = 1e-8;
const D INF = 1e9;
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

std::istream &operator>>(std::istream &is, Point &a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

std::ostream &operator<<(std::ostream &os, Point &a) {
  os << std::real(a) << " " << std::imag(a);
  return os;
}

std::istream &operator>>(std::istream &is, Line &l) {
  Point p1, p2;
  is >> p1 >> p2;
  l = Line(p1, p2);
  return is;
}

D dot(const Point &a, const Point &b) {
  return std::real(a) * std::real(b) + std::imag(a) * std::imag(b);
}

D cross(const Point &a, const Point &b) {
  return std::real(a) * std::imag(b) - std::imag(a) * std::real(b);
}

Point projection(const Point &a, const Point &b) { return a * std::real(b / a); }

int main() {
  Line L;
  std::cin >> L;
  int Q;
  std::cin >> Q;
  while (Q--) {
    Point p;
    std::cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    std::cout << w << '\n';
  }
  return 0;
}