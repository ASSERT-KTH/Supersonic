#include <complex>
#include <iostream>
using namespace std;
using Point = complex<double>;

namespace std {
bool operator<(const Point &a, const Point &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
} // namespace std

double cross_prod(const Point &a, const Point &b) { return imag(conj(a) * b); }
double dot_prod(const Point &a, const Point &b) { return real(conj(a) * b); }

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(double ax, double ay, double bx, double by, double cx, double cy) {
  Point a(ax, ay), b(bx, by), c(cx, cy);
  b -= a;
  c -= a;
  double cross = cross_prod(b, c);
  double dot = dot_prod(b, c);
  if (cross > 0) {
    return COUNTER_CLOCKWISE;
  } else if (cross < 0) {
    return CLOCKWISE;
  } else if (dot < 0) {
    return ONLINE_BACK;
  } else if (norm(b) < norm(c)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double ax, ay, bx, by, cx, cy, px, py;
  if (!(cin >> ax >> ay >> bx >> by >> cx >> cy >> px >> py))
    return true;
  CCWiseState tmp = ccwise(ax, ay, px, py, bx, by);
  if (tmp != ccwise(bx, by, px, py, cx, cy)) {
    cout << "NO\n";
    return true;
  } else if (tmp != ccwise(cx, cy, px, py, ax, ay)) {
    cout << "NO\n";
    return true;
  }
  cout << "YES\n";
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int solved = 0;
  while (!testcase_ends())
    ++solved;
  return !solved;
}