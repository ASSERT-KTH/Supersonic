#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
using namespace std;

using D = double;
const D EPS = 1e-8;
const D INF = 1e9;
using Point = complex<D>;
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
using Polygon = vector<Point>;

istream &operator>>(istream &is, Point &a) {
  D x, y;
  scanf("%lf %lf", &x, &y);
  a = Point(x, y);
  return is;
}

ostream &operator<<(ostream &os, Point &a) {
  os << fixed << setprecision(15) << real(a) << " " << imag(a);
  return os;
}

istream &operator>>(istream &is, Line &l) {
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

Point projection(const Point &a, const Point &b) {
  return a * real(b / a);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  Line L;
  cin >> L;

  int Q;
  cin >> Q;

  Point p1 = L.p1;
  Point p2 = L.p2;
  Point v = p2 - p1;
  D dot_vv = dot(v, v);

  while (Q--) {
    Point p;
    cin >> p;
    Point w = p1 + projection(v, p - p1);
    printf("%.15lf %.15lf\n", real(w), imag(w));
  }
  
  return 0;
}