#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

using namespace std;

using D = double;
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
  os << real(a) << " " << imag(a);
  return os;
}

istream &operator>>(istream &is, Line &l) {
  is >> l.p1 >> l.p2;
  return is;
}

Point projection(const Line& l, const Point &p) { 
    D r = real((p - l.p1) / (l.p2 - l.p1));
    return l.p1 + (l.p2 - l.p1) * r; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);

  Line L;
  cin >> L;

  int Q;
  cin >> Q;

  while (Q--) {
    Point p;
    cin >> p;
    cout << projection(L, p) << "\n";
  }

  return 0;
}