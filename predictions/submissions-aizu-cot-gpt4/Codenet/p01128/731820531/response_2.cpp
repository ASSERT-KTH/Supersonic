#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(), (c).end()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pint;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const double PI = acos(-1.0);
typedef double gtype;
const gtype EPS_FOR_LIB = 1e-9;
typedef complex<gtype> Point;
gtype to_rad(gtype deg) { return deg * PI / 180; }
gtype to_deg(gtype rad) { return rad * 180 / PI; }
namespace std {
bool operator<(const Point &a, const Point &b) {
  return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}
std::istream &operator>>(std::istream &is, Point &p) {
  gtype a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}
std::ostream &operator<<(std::ostream &os, const Point &p) {
  return os << "(" << p.real() << ", " << p.imag() << ")";
}
}; // namespace std
struct Line {
  Point first, second;
  Line() {}
  Line(const Point &first, const Point &second) : first(first), second(second) {
    if (first == second)
      this->first.real() += 1e-12;
  }
};
typedef Line Seg;
ostream &operator<<(ostream &os, const Line &line) {
  return os << "(" << line.first << ", " << line.second << ")";
}
struct Circle {
  Point p;
  gtype r;
  Circle() {}
  Circle(const Point &p, gtype r) : p(p), r(r) {}
};
ostream &operator<<(ostream &os, const Circle &c) {
  return os << "(" << c.p << ", " << c.r << ")";
}
typedef vector<Point> G;
typedef G Convex;
Seg side_G(const G &g, int i) { return Seg(g[i], g[(i + 1) % g.size()]); }
gtype dot(const Point &a, const Point &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
gtype cross(const Point &a, const Point &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
enum res_ccw {
  counter_clockwise = +1,
  clockwise = -1,
  on = 0,
};
res_ccw ccw(const Point &a, const Point &b, const Point &c) {
  const gtype feps = 1e-10;
  Point p = b - a, q = c - a;
  if (cross(p, q) > feps)
    return counter_clockwise;
  else if (cross(p, q) < -feps)
    return clockwise;
  return on;
}
bool is_orthogonal(const Line &line1, const Line &line2) {
  return abs(dot(line1.second - line1.first, line2.second - line2.first)) <
         1e-9;
}
bool is_parallel(const Line &line1, const Line &line2) {
  return abs(cross(line1.second - line1.first, line2.second - line2.first)) <
         1e-9;
}
bool intersect_LP(const Line &line, const Point &p) {
  return abs(cross(line.second - line.first, p - line.first)) < 1e-20;
}
bool intersect_SP(const Line &seg, const Point &p) {
  return abs(seg.first - p) + abs(p - seg.second) <
         abs(seg.first - seg.second) + EPS_FOR_LIB;
}
bool intersect_LL(const Line &line1, const Line &line2) {
  return !is_parallel(line1, line2);
}
bool intersect_LS(const Line &line, const Line &seg) {
  return cross(line.second - line.first, seg.first - line.first) *
             cross(line.second - line.first, seg.second - line.first) <
         EPS_FOR_LIB;
}
bool intersect_SL(const Line &seg, const Line &line) {
  return intersect_LS(line, seg);
}
bool intersect_SS(const Line &seg1, const Line &seg2) {
  const gtype feps = 1e-9;
  return (cross(seg1.second - seg1.first, seg2.first - seg1.first) *
                  cross(seg1.second - seg1.first, seg2.second - seg1.first) <
              -feps &&
          cross(seg2.second - seg2.first, seg1.first - seg2.first) *
                  cross(seg2.second - seg2.first, seg1.second - seg2.first) <
              -feps) ||
         intersect_SP(seg1, seg2.first) || intersect_SP(seg1, seg2.second) ||
         intersect_SP(seg2, seg1.first) || intersect_SP(seg2, seg1.second);
}
gtype dist_LP(const Line &line, const Point &p) {
  return abs(cross(line.first - line.second, p - line.second) /
             abs(line.first - line.second));
}
gtype dist_PL(const Point &p, const Line &line) { return dist_LP(line, p); }
gtype dist_LL(const Line &line1, const Line &line2) {
  return is_parallel(line1, line2) ? dist_LP(line1, line2.first) : 0;
}
gtype dist_LS(const Line &line, const Line &seg) {
  if (intersect_LS(line, seg))
    return 0;
  else
    return min(dist_LP(line, seg.first), dist_LP(line, seg.second));
}
gtype dist_SL(const Line &seg, const Line &line) { return dist_LS(line, seg); }
gtype dist_SP(const Line &seg, const Point &p) {
  if (dot(seg.second - seg.first, p - seg.first) < 0)
    return abs(seg.first - p);
  else if (dot(seg.first - seg.second, p - seg.second) < 0)
    return abs(seg.second - p);
  else
    return dist_LP(seg, p);
}
gtype dist_PS(const Point &p, const Line &seg) { return dist_SP(seg, p); }
gtype dist_SS(const Line &seg1, const Line &seg2) {
  if (intersect_SS(seg1, seg2))
    return 0;
  else
    return min(min(dist_SP(seg1, seg2.first), dist_SP(seg1, seg2.second)),
               min(dist_SP(seg2, seg1.first), dist_SP(seg2, seg1.second)));
}
Point ip_SS(const Line &seg1, const Line &seg2) {
  if (!intersect_SS(seg1, seg2)) {
    cerr << "ip_SS: 前提条件満たしてない" << endl;
    exit(1);
  }
  gtype a = abs(cross(seg1.second - seg1.first, seg2.first - seg1.first));
  gtype b = abs(cross(seg1.second - seg1.first, seg2.second - seg1.first));
  if (a < 1e-9 && b < 1e-9) {
    cerr << "same line" << endl;
    exit(1);
  }
  gtype t = a / (a + b);
  return seg2.first + t * (seg2.second - seg2.first);
}
Point ip_LL(const Line &line1, const Line &line2) {
  if (is_parallel(line1, line2)) {
    cerr << "ip_LL: 前提条件満たしてない" << endl;
    exit(1);
  }
  Point a = line1.second - line1.first, b = line2.second - line2.first;
  gtype p = cross(b, line2.first - line1.first);
  gtype q = cross(b, a);
  return line1.first + p / q * a;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    Seg s;
    cin >> s.first >> s.second;
    Point rota(1, -arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    vector<pair<Point, bool>> c;
    int n;
    cin >> n;
    rep(i, n) {
      Seg t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (intersect_SS(s, t))
        c.pb(mp(ip_SS(s, t), (o ^ l)));
    }
    sort(all(c));
    int res = 0;
    rep(i, (int)c.size() - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}