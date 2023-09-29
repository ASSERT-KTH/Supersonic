#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
using D = double;
const D EPS = 1e-8;
const D INF = 1e9;

using Point = complex<D>;
struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

istream &operator>>(istream &is, Point &a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

ostream &operator<<(ostream &os, const Point &a) {
  return os << real(a) << " " << imag(a);
}

istream &operator>>(istream &is, Line &l) {
  return is >> l.p1 >> l.p2;
}

Point projection(const Line &l, const Point &p) {
  Point base = l.p2 - l.p1;
  D r = dot(p - l.p1, base) / norm(base);
  return l.p1 + base * r;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  
  Line L; cin >> L;
  int Q; cin >> Q;
  vector<Point> points(Q);
  for (Point &p : points) cin >> p;
  
  for (const Point &p : points) {
    cout << projection(L, p) << "\n";
  }
}