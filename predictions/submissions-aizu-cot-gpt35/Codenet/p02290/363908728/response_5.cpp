#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>

using namespace std;

using D = double;
using Point = complex<D>;
using Polygon = vector<Point>;

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

struct Line {
  Point p1, p2;
  Line(const Point &p1 = Point(), const Point &p2 = Point()) : p1(p1), p2(p2) {}
};

Point projection(const Point &a, const Point &b) {
  return a * conj(b) / norm(a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);

  Line L;
  cin >> L;

  int Q;
  scanf("%d", &Q);

  while (Q--) {
    Point p;
    cin >> p;
    Point w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    printf("%.15f %.15f\n", real(w), imag(w));
  }

  return 0;
}