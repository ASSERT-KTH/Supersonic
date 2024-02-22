#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
using namespace std;
struct Segment {
  complex<double> p1, p2;
  Segment(const complex<double> &p1 = complex<double>(), const complex<double> &p2 = complex<double>())
      : p1(p1), p2(p2) {}
};
struct Line {
  complex<double> p1, p2;
  Line(const complex<double> &p1 = complex<double>(), const complex<double> &p2 = complex<double>()) : p1(p1), p2(p2) {}
};
struct Circle {
  complex<double> c;
  double r;
  Circle(const complex<double> &c = complex<double>(), const double &r = 0.0) : c(c), r(r) {}
};
using Polygon = vector<complex<double>>;
double dot(const complex<double> &a, const complex<double> &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}
double cross(const complex<double> &a, const complex<double> &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}
complex<double> projection(const complex<double> &a, const complex<double> &b) { return a * real(b / a); }
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(15);
  Line L;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  L = Line(complex<double>(x1, y1), complex<double>(x2, y2));
  int Q;
  cin >> Q;
  while (Q--) {
    double x, y;
    cin >> x >> y;
    complex<double> p = complex<double>(x, y);
    complex<double> w = L.p1 + projection(L.p2 - L.p1, p - L.p1);
    cout << real(w) << " " << imag(w) << '\n';
  }
  return 0;
}