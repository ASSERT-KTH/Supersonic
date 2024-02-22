#include <bits/stdc++.h>
using namespace std;

struct CWW {
  CWW() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} STAR;

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

Point projection(const Point &a, const Point &b) {
  return a * dot(a, b) / norm(a);
}

int main() {
  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  stringstream ss;
  while (Q--) {
    Point p;
    cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    ss << w << "\n";
  }
  cout << ss.str();
  return 0;
}