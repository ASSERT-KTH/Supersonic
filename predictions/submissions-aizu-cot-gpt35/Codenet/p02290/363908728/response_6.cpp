#include <iostream>
#include <complex>
#include <vector>
using namespace std;

using D = double;
using Point = complex<D>;

struct Line {
  Point p1, p2;
  Line(const Point& p1 = Point(), const Point& p2 = Point()) : p1(p1), p2(p2) {}
};

istream& operator>>(istream& is, Point& a) {
  D x, y;
  is >> x >> y;
  a = Point(x, y);
  return is;
}

istream& operator>>(istream& is, Line& l) {
  Point p1, p2;
  is >> p1 >> p2;
  l = Line(p1, p2);
  return is;
}

D dot(const Point& a, const Point& b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

D cross(const Point& a, const Point& b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Point projection(const Point& a, const Point& b) {
  return a * real(b / a);
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