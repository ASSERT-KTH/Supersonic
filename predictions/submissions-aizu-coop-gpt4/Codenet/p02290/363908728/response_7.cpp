#include <iostream>
#include <vector>
#include <complex>

using namespace std;
using D = double;

struct Point {
  D x, y;
  Point(D x = 0.0, D y = 0.0) : x(x), y(y) {}
};

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

istream &operator>>(istream &is, Point &a) {
  is >> a.x >> a.y;
  return is;
}

ostream &operator<<(ostream &os, const Point &a) {
  os << a.x << " " << a.y;
  return os;
}

istream &operator>>(istream &is, Line &l) {
  is >> l.p1 >> l.p2;
  return is;
}

Point projection(const Point &l1, const Point &l2, const Point &p) {
  D t = ((p.x - l1.x) * (l2.x - l1.x) + (p.y - l1.y) * (l2.y - l1.y)) / 
        ((l2.x - l1.x) * (l2.x - l1.x) + (l2.y - l1.y) * (l2.y - l1.y));
  return Point(l1.x + t * (l2.x - l1.x), l1.y + t * (l2.y - l1.y));
}

int main() {
  ios_base::sync_with_stdio(false);

  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  while (Q--) {
    Point p;
    cin >> p;
    Point w = projection(L.p1, L.p2, p);
    cout << w << "\n";
  }
  return 0;
}