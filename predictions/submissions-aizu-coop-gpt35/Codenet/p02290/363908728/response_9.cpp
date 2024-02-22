#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

struct CWW {
  CWW() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} STAR;

using D = double;
const D EPS = 1e-8;
const D INF = 1e9;

struct Point {
  D x, y;
};

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
  return is >> a.x >> a.y;
}

ostream &operator<<(ostream &os, const Point &a) {
  return os << a.x << " " << a.y;
}

istream &operator>>(istream &is, Line &l) {
  return is >> l.p1 >> l.p2;
}

D dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

D cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

Point projection(const Point &a, const Point &b) {
  return {a.x * (b.x / (a.x * a.x + a.y * a.y)), a.y * (b.x / (a.x * a.x + a.y * a.y))};
}

int main() {
  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  while (Q--) {
    Point p;
    cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    cout << w << endl;
  }
  return 0;
}