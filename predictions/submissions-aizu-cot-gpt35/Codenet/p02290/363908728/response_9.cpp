#include <iostream>
#include <complex>
#include <vector>

using namespace std;

using D = double;
using Point = complex<D>;
using Polygon = vector<Point>;

struct Segment {
  Point p1, p2;
  Segment(const Point& p1 = Point(), const Point& p2 = Point()) : p1(p1), p2(p2) {}
};

struct Line {
  Point p1, p2;
  Line(const Point& p1 = Point(), const Point& p2 = Point()) : p1(p1), p2(p2) {}
};

struct Circle {
  Point c;
  D r;
  Circle(const Point& c = Point(), const D& r = 0.0) : c(c), r(r) {}
};

istream& operator>>(istream& is, Point& a) {
  D x, y;
  scanf("%lf %lf", &x, &y);
  a = Point(x, y);
  return is;
}

ostream& operator<<(ostream& os, Point& a) {
  printf("%.15lf %.15lf", real(a), imag(a));
  return os;
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
  return a * dot(a, b) / dot(a, a);
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