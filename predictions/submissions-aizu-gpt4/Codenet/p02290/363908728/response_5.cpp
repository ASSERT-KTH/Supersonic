#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::complex;

using D = double;
using Point = complex<D>;
struct Line {
  Point p1, p2;
};

D dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

Point projection(const Line &l, const Point &p) {
  Point w = l.p1 - l.p2;
  return l.p2 + w * dot(p - l.p2, w) / norm(w);
}

int main() {
  std::ios::sync_with_stdio(false);
  cout << std::fixed << std::setprecision(15);

  Line L;
  D x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  L.p1 = {x1, y1};
  L.p2 = {x2, y2};

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; ++i) {
    D x, y;
    cin >> x >> y;
    Point p = {x, y};
    Point w = projection(L, p);
    cout << real(w) << " " << imag(w) << endl;
  }

  return 0;
}