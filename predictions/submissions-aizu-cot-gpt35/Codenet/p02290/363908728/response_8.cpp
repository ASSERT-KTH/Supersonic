#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};

struct Line {
  Point p1, p2;
};

istream &operator>>(istream &is, Point &a) {
  return is >> a.x >> a.y;
}

ostream &operator<<(ostream &os, Point &a) {
  return os << a.x << " " << a.y;
}

istream &operator>>(istream &is, Line &l) {
  return is >> l.p1 >> l.p2;
}

Point projection(const Point &a, const Point &b) {
  return {a.x * b.x / (a.x * a.x + a.y * a.y), a.y * b.y / (a.x * a.x + a.y * a.y)};
}

int main() {
  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  while (Q--) {
    Point p;
    cin >> p;
    Point w = {L.p1.x + projection(L.p2 - L.p1, p - L.p1).x, L.p1.y + projection(L.p2 - L.p1, p - L.p1).y};
    cout << fixed << setprecision(15) << w << '\n';
  }
  return 0;
}