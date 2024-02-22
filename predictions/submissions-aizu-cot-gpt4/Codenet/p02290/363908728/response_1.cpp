#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>

struct CWW {
  CWW() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
  }
} STAR;

using D = double;
using Point = std::complex<D>;
struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

std::istream &operator>>(std::istream &is, Point &a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

std::ostream &operator<<(std::ostream &os, const Point &a) {
  os << real(a) << " " << imag(a);
  return os;
}

std::istream &operator>>(std::istream &is, Line &l) {
  Point p1, p2;
  is >> p1 >> p2;
  l = Line(p1, p2);
  return is;
}

D dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

Point projection(const Point &a, const Point &b) { return a * real(b / a); }

int main() {
  Line L;
  std::cin >> L;
  int Q;
  std::cin >> Q;
  for (; Q > 0; --Q) {
    Point p;
    std::cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    std::cout << w << '\n';
  }
  return 0;
}