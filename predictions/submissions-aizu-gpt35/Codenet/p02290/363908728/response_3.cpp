#include <iostream>
#include <complex>
#include <iomanip>
using namespace std;
using D = double;
using Point = complex<D>;

const D EPS = 1e-8;

istream &operator>>(istream &is, Point &a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

ostream &operator<<(ostream &os, Point &a) {
  os << fixed << setprecision(15) << real(a) << " " << imag(a);
  return os;
}

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

D dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

D cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Point projection(const Point &a, const Point &b) { return a * real(b / a); }

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  Line L;
  cin >> L;
  int Q;
  cin >> Q;
  while (Q--) {
    Point p;
    cin >> p;
    Point v = L.p2 - L.p1;
    Point w = p - L.p1;
    D c1 = dot(w, v);
    D c2 = dot(v, v);
    Point res = L.p1 + v * (c1 / c2);
    cout << res << endl;
  }
  return 0;
}