#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(it, c)                                                         \
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define rforeach(it, c)                                                        \
  for (__typeof__((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
#define ten(n) ((long long)(1e##n))
#define bin(n) (1LL << (n))
#define erep(i, n) for (int i = 0; i <= (int)(n); ++i)
#define revrep(i, n) for (int i = (n); i >= 0; --i)
#define pb push_back
template <class T> void chmax(T &a, const T &b) { a = max(a, b); }
template <class T> void chmin(T &a, const T &b) { a = min(a, b); }
template <class T> void uniq(T &c) {
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
}
template <class T> string to_s(const T &a) {
  ostringstream os;
  os << a;
  return os.str();
}
template <class T> T to_T(const string &s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <typename T> void print_container(ostream &os, const T &c) {
  const char *_s = " ";
  if (!c.empty()) {
    __typeof__(c.begin()) last = --c.end();
    foreach (it, c) {
      os << *it;
      if (it != last)
        cout << _s;
    }
  }
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &c) {
  print_container(os, c);
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &c) {
  print_container(os, c);
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &c) {
  print_container(os, c);
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const deque<T> &c) {
  print_container(os, c);
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &c) {
  print_container(os, c);
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "( " << p.first << ", " << p.second << " )";
  return os;
}
template <class T>
void print(T a, int n, const string &deli = " ", int br = 1) {
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n)
      cout << deli;
  }
  while (br--)
    cout << endl;
}
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (width != -1)
        cout.width(width);
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  while (br--)
    cout << endl;
}
template <class T> void input(T &a, int n) {
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}
template <class T> void input(T *a, int n) {
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}
void fix_pre(int n) {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);
}
void fast_io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}
#define trace(x) (cout << #x << ": " << (x) << endl)
bool in_rect(int x, int y, int w, int h) {
  return 0 <= x && x < w && 0 <= y && y < h;
}
bool in_seg(int n, int l, int r) { return l <= n && n < r; }
typedef long long ll;
typedef pair<int, int> pint;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const double PI = acos(-1.0);
#define mp make_pair
typedef double gtype;
const gtype EPS_FOR_LIB = 1e-9;
typedef complex<gtype> Point;
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
  return (cross(seg1.second - seg1.first, seg2.first - seg1.first) *
                  cross(seg1.second - seg1.first, seg2.second - seg1.first) <
              -EPS_FOR_LIB &&
          cross(seg2.second - seg2.first, seg1.first - seg2.first) *
                  cross(seg2.second - seg2.first, seg1.second - seg2.first) <
              -EPS_FOR_LIB) ||
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
Point rotate(const Point &p, gtype angle) {
  gtype c = cos(angle), s = sin(angle);
  return Point(p.real() * c - p.imag() * s, p.real() * s + p.imag() * c);
}
Point rotate(const Point &p, gtype angle, const Point &base) {
  Point t = p - base;
  return rotate(t, angle) + base;
}
Point projection(const Line &line, const Point &p) {
  Point a = line.first - line.second;
  gtype t = dot(p - line.first, a) / norm(a);
  return line.first + t * a;
}
Point reflection(const Line &line, const Point &p) {
  return p + ((gtype)2) * (projection(line, p) - p);
}
struct Rect {
  Point low, high;
  Rect(Point low, Point high) : low(low), high(high) {}
  Rect() {}
  gtype x1() const { return low.real(); }
  gtype x2() const { return high.real(); }
  gtype y1() const { return low.imag(); }
  gtype y2() const { return high.imag(); }
  Point top_left() const { return Point(x1(), y2()); }
  Point bottom_left() const { return Point(x1(), y1()); }
  Point bottom_right() const { return Point(x2(), y1()); }
  Point top_right() const { return Point(x2(), y2()); }
  G to_g() const {
    G res;
    res.push_back(top_left());
    res.push_back(bottom_left());
    res.push_back(bottom_right());
    res.push_back(top_right());
    return res;
  }
};
bool intersect_rect_area(const Rect &a, const Rect &b) {
  bool x = a.low.real() < b.high.real() && a.high.real() > b.low.real();
  bool y = a.low.imag() < b.high.imag() && a.high.imag() > b.low.imag();
  return x && y;
}
bool intersect_rect(const Rect &a, const Rect &b) {
  bool x = !(a.low.real() > b.high.real()) && !(a.high.real() < b.low.real());
  bool y = !(a.low.imag() > b.high.imag()) && !(a.high.imag() < b.low.imag());
  return x && y;
}
vector<Point> corner(const Rect &r) {
  gtype x[] = {r.low.real(), r.high.real()};
  gtype y[] = {r.low.imag(), r.high.imag()};
  vector<Point> res;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      res.push_back(Point(x[i], y[j]));
  return res;
}
bool allow_line(res_ccw r) { return r < 0; }
bool strict(res_ccw r) { return r <= 0; }
G convex_hull(vector<Point> ps, bool f(res_ccw) = strict) {
  sort(ps.begin(), ps.end());
  ps.erase(unique(ps.begin(), ps.end()), ps.end());
  int n = ps.size(), k = 0;
  G res;
  res.resize(2 * n);
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && f(ccw(res[k - 2], res[k - 1], ps[i])))
      --k;
    res[k++] = ps[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; --i) {
    while (k >= t && f(ccw(res[k - 2], res[k - 1], ps[i])))
      --k;
    res[k++] = ps[i];
  }
  res.resize(k - 1);
  return res;
}
bool is_convex(const G &g) {
  for (int i = 0; i < (int)g.size(); ++i) {
    if (ccw(g[(i - 1 + g.size()) % g.size()], g[i], g[(i + 1) % g.size()]) < 0)
      return false;
  }
  return true;
}
gtype area(const G &g) {
  gtype s = 0;
  for (int i = 0; i < (int)g.size(); ++i)
    s += cross(g[i], g[(i + 1) % g.size()]);
  return abs(s / 2);
}
enum res_contain { OUT, ON, IN };
res_contain contain_GP(const G &g, const Point &p) {
  bool in = false;
  for (int i = 0; i < (int)g.size(); ++i) {
    Point a = g[i] - p, b = g[(i + 1) % g.size()] - p;
    if (a.imag() > b.imag())
      swap(a, b);
    if ((a.imag() <= 0 && 0 < b.imag()) && cross(a, b) < 0)
      in = !in;
    if (intersect_SP(Line(g[i], g[(i + 1) % g.size()]), p))
      return ON;
  }
  return in ? IN : OUT;
}
bool contain_GG(const G &a, const G &b) {
  rep(i, b.size()) if (contain_GP(a, b[i]) == OUT) return false;
  return true;
}
bool intersect_GG(const G &a, const G &b) {
  rep(i, a.size())
      rep(j, b.size()) if (intersect_SS(
                               Line(a[i], a[(i + 1) % a.size()]),
                               Line(b[j], b[(j + 1) % b.size()]))) return true;
  return contain_GG(a, b) || contain_GG(b, a);
}
enum res_pos_CC {
  not_intersect,
  intersect,
  tangent,
  a_in_b,
  b_in_a,
};
res_pos_CC pos_CC(const Circle &a, const Circle &b) {
  const gtype feps = 1e-10;
  gtype d = abs(a.p - b.p);
  if (d + feps > a.r + b.r)
    return not_intersect;
  else {
    if (d + feps < a.r - b.r)
      return b_in_a;
    else if (d + feps < b.r - a.r)
      return a_in_b;
    else
      return intersect;
  }
}
bool intersect_GC(const G &g, const Circle &c) {
  for (int i = 0; i < (int)g.size(); ++i)
    if (dist_SP(Line(g[i], g[(i + 1) % g.size()]), c.p) < c.r + 1e-9)
      return true;
  return contain_GP(g, c.p) != OUT;
}
res_contain contain_CP(const Circle &c, const Point &p) {
  const gtype feps = 1e-9;
  gtype d = abs(c.p - p);
  if (d > c.r + feps)
    return OUT;
  else if (d < c.r + feps)
    return IN;
  else
    return ON;
}
bool intersect_CS(const Circle &c, const Line &seg) {
  if (contain_CP(c, seg.first) && contain_CP(c, seg.second))
    return false;
  return dist_SP(seg, c.p) < c.r + 1e-9;
}
bool intersect_SC(const Line &seg, const Circle &c) {
  return intersect_CS(c, seg);
}
vector<Point> ip_CC(const Circle &a, const Circle &b) {
  const gtype feps = 1e-9;
  if (pos_CC(a, b) != intersect)
    return vector<Point>();
  Point ab = b.p - a.p;
  gtype t = (norm(ab) + a.r * a.r - b.r * b.r) / (2 * abs(ab));
  Point u = ab / abs(ab);
  Point q = a.p + t * u;
  gtype h = sqrt(max<gtype>(0, a.r * a.r - t * t));
  Point v = Point(0, h) * u;
  vector<Point> res;
  res.pb(q + v);
  if (h > feps)
    res.pb(q - v);
  return res;
}
vector<Point> ip_CL(const Circle &c, const Line &line) {
  const gtype feps = 1e-9;
  Point p = projection(line, c.p);
  Point cp = p - c.p;
  gtype d = abs(cp);
  if (d > c.r + feps)
    return vector<Point>();
  gtype t = sqrt(max<gtype>(0, c.r * c.r - d * d));
  Point u = line.second - line.first;
  Point v = u / abs(u) * t;
  vector<Point> res;
  res.pb(p + v);
  if (t > feps)
    res.pb(p - v);
  return res;
}
vector<Point> ip_LC(const Line &line, const Circle &c) {
  return ip_CL(c, line);
}
vector<Point> ip_CS(const Circle &c, const Seg &seg) {
  vector<Point> ip = ip_CL(c, seg);
  vector<Point> res;
  rep(i, ip.size()) if (intersect_SP(seg, ip[i])) res.pb(ip[i]);
  return res;
}
vector<Point> ip_SC(const Seg &seg, const Circle &c) { return ip_CS(c, seg); }
string replace(const string &str, const string &from, const string &to) {
  string res = str;
  string::size_type p;
  while ((p = res.find(from)) != string::npos)
    res.replace(p, from.size(), to);
  return res;
}
int n;
Circle c[111];
Point ip[111][2];
bool reachable(int i, int a, int j, int b) {
  Seg seg(ip[i][a], ip[j][b]);
  Point vec = seg.second - seg.first;
  vec *= 1e-2 / abs(vec);
  rep(w, n) {
    vector<Point> pp = ip_CS(c[w], seg);
    foreach (p, pp) {
      bool ok = false;
      rep(t, n) {
        if (contain_CP(c[t], *p + vec)) {
          ok = true;
          break;
        }
      }
      if (!ok)
        return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n, n) {
    rep(i, n) cin >> c[i].p >> c[i].r;
    rep(i, 2) {
      ip[0][i] = c[0].p;
      ip[n][i] = c[n - 1].p;
    }
    rep(i, n - 1) {
      vector<Point> t = ip_CC(c[i], c[i + 1]);
      assert(t.size() == 2);
      ip[i + 1][0] = t[0], ip[i + 1][1] = t[1];
    }
    const double eps = 1e-9;
    const double inf = 1e9;
    typedef pair<double, pint> P;
    priority_queue<P, vector<P>, greater<P>> q;
    double dp[111][2];
    erep(i, n) rep(j, 2) dp[i][j] = inf;
    dp[0][0] = dp[0][1] = 0;
    q.push(P(0, pint(0, 0)));
    double res = -1;
    while (!q.empty()) {
      P t = q.top();
      q.pop();
      int u = t.second.first, w = t.second.second;
      double d = t.first;
      if (d > dp[u][w] + eps)
        continue;
      else if (u == n) {
        res = d;
        break;
      }
      for (int v = u; v <= n; ++v)
        rep(s, 2) {
          if (reachable(u, w, v, s)) {
            double nd = d + abs(ip[v][s] - ip[u][w]);
            if (nd + eps < dp[v][s]) {
              dp[v][s] = nd;
              q.push(P(nd, pint(v, s)));
            }
          }
        }
    }
    assert(res >= 0);
    printf("%.6f\n", res);
  }
}
