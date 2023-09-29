#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

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
  os << std::fixed << std::setprecision(10) << a.real() << " " << a.imag();
  return os;
}
std::istream &operator>>(std::istream &is, Line &l) {
  Point p1, p2;
  is >> p1 >> p2;
  l = Line(p1, p2);
  return is;
}
Point projection(const Point &a, const Point &b) { return a * std::real(b / a); }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Line L;
  std::cin >> L;
  int Q;
  std::cin >> Q;
  while (Q--) {
    Point p;
    std::cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    std::cout << w << "\n";
  }
  return 0;
}