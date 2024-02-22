#include <iostream>
#include <vector>

using namespace std;

struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &a, double b) {
  return Point(a.x * b, a.y * b);
}

istream &operator>>(istream &is, Point &a) {
  return is >> a.x >> a.y;
}

istream &operator>>(istream &is, Line &l) {
  return is >> l.p1 >> l.p2;
}

ostream &operator<<(ostream &os, const Point &a) {
  return os << a.x << " " << a.y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Line L;
  cin >> L;

  int Q;
  cin >> Q;

  Point p, w;
  cout.precision(15);
  cout << fixed;

  for (int i = 0; i < Q; ++i) {
    cin >> p;

    Point v = L.p2 - L.p1;
    double t = dot(p - L.p1, v) / dot(v, v);
    w = L.p1 + v * t;

    cout << w << "\n";
  }

  return 0;
}