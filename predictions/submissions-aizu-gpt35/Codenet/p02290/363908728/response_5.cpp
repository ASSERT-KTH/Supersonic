#include <bits/stdc++.h>
using namespace std;
using D = double;
const D EPS = 1e-8;
const D INF = 1e9;
struct Point {
  D x, y;
  Point(D x = 0.0, D y = 0.0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(D a) { return Point(x * a, y * a); }
  Point operator/(D a) { return Point(x / a, y / a); }
  bool operator<(const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
using Vector = Point;
struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};
using Line = Segment;
struct Circle {
  Point c;
  D r;
  Circle(Point c = Point(), D r = 0.0) : c(c), r(r) {}
};
using Polygon = vector<Point>;
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}
ostream &operator<<(ostream &os, Point &p) {
  os << p.x << " " << p.y;
  return os;
}
istream &operator>>(istream &is, Line &l) {
  is >> l.p1 >> l.p2;
  return is;
}
D dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}
D cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}
Point projection(Point p, Line l) {
  Vector v = l.p2 - l.p1;
  D t = dot(p - l.p1, v) / dot(v, v);
  return l.p1 + v * t;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(15);
  Line l;
  cin >> l;
  int q;
  cin >> q;
  while (q--) {
    Point p;
    cin >> p;
    Point w = projection(p, l);
    cout << w << "\n";
  }
  return 0;
}