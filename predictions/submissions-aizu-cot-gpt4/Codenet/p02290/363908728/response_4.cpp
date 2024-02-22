#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

using D = double;
const D EPS = 1e-8;
const D INF = 1e9;
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

std::ostream &operator<<(std::ostream &os, Point &a) {
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

D cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Point projection(const Point &a, const Point &b) { return a * real(b / a); }

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(15);
  
  Line L;
  std::cin >> L;
  Point Lp = L.p2 - L.p1;
  
  for(int Q; std::cin >> Q && Q--; ) {
    Point p;
    std::cin >> p;
    Point w = L.p1 + projection(Lp, p - L.p1);
    std::cout << w << '\n';
  }
  
  return 0;
}