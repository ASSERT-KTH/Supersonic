#include <bits/stdc++.h>
using namespace std;
struct CWW {
  CWW() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} STAR;
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
  Point p1, p2, v;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2), v(p2 - p1) {}
};
struct Circle {
  Point c;
  D r;
  Circle(const Point &c = Point(), const D &r = 0.0) : c(c), r(r) {}
};
using Polygon = vector<Point>;
istream &operator>>(istream &is, Point &a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}
ostream &operator<<(ostream &os, Point &a) {
  os << real(a) << " " << imag(a);
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
Point projection(const Point &a, const Point &b) { return a * real(b / a); }
int main() {
  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  while (Q--) {
    Point p;
    cin >> p;
    Point w = L.p1 + projection(L.v, p - L.p1);
    cout << w << endl;
  }
  return 0;
}