#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <valarray>
#include <vector>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define RFOR(i, c)                                                             \
  for (__typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  FOR(it, t) {
    if (it != t.begin())
      os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  FOR(it, t) {
    if (it != t.begin())
      os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}
  bool unionSet(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};
namespace geom {
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
enum { TRUE = 1, FALSE = 0, BORDER = -1 };
typedef int BOOL;
typedef double R;
const R INF = 1e8;
const R EPS = 1e-8;
const R PI = 3.1415926535897932384626;
inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
inline BOOL less(const R &x, const R &y) { return sig(x - y) ? x < y : BORDER; }
typedef complex<R> P;
inline R norm(const P &p) { return p.X * p.X + p.Y * p.Y; }
inline R inp(const P &a, const P &b) { return (conj(a) * b).X; }
inline R outp(const P &a, const P &b) { return (conj(a) * b).Y; }
inline P unit(const P &p) { return p / abs(p); }
inline P proj(const P &s, const P &t) { return t * inp(s, t) / norm(t); }
inline int ccw(const P &s, const P &t, const P &p, int adv = 0) {
  int res = sig(outp(t - s, p - s));
  if (res || !adv)
    return res;
  if (sig(inp(t - s, p - s)) < 0)
    return -2;
  if (sig(inp(s - t, p - t)) < 0)
    return 2;
  return 0;
}
struct L : public vector<P> {
  L(const P &p1, const P &p2) {
    this->push_back(p1);
    this->push_back(p2);
  }
  L() {}
  P dir() const { return at(1) - at(0); }
  BOOL online(const P &p) const { return !sig(outp(p - at(0), dir())); }
};
struct S : public L {
  S(const P &p1, const P &p2) : L(p1, p2) {}
  S() {}
  BOOL online(const P &p) const {
    if (!sig(norm(p - at(0))) || !sig(norm(p - at(1))))
      return BORDER;
    return !sig(abs(at(0) - p) + abs(at(1) - p) - abs(at(0) - at(1)));
  }
};
struct C : public P {
  C() {}
  C(const P &p, const R r) : P(p), r(r) {}
  R r;
  BOOL inside(const P &p) const { return less(norm(p - SELF), r * r); }
};
struct F : public C {
  R s, t;
  F(const C &c, R ss, R tt) : C(c), s(ss), t(tt) {
    if (PI < s)
      s -= 2 * PI;
    if (PI < t)
      t -= 2 * PI;
  }
  BOOL inside(const P &p) const {
    P v = p - SELF;
    if (!sig(norm(v)))
      return BORDER;
    R a = arg(v);
    if (t < s) {
      if ((!less(s, a) && !less(a, t)) || !less(norm(v), r * r))
        return FALSE;
      return less(s, a) | less(a, t) | less(norm(v), r * r);
    } else {
      if (!less(s, a) || !less(a, t) || !less(norm(v), r * r))
        return FALSE;
      return less(s, a) | less(a, t) | less(norm(v), r * r);
    }
  }
};
P crosspoint(const L &l, const L &m);
struct G : public vector<P> {
  G(size_type size = 0) : vector(size) {}
  S edge(int i) const { return S(at(i), at(i + 1 == size() ? 0 : i + 1)); }
  BOOL contains(const P &p) const {
    R sum = .0;
    REP(i, size()) {
      if (S(at(i), at((i + 1) % size())).online(p))
        return BORDER;
      sum += arg((at(i) - p) / (at((i + 1) % size()) - p));
    }
    return !!sig(sum);
  }
  R area() const {
    R sum = 0;
    REP(i, size()) sum += outp(at(i), at((i + 1) % size()));
    return abs(sum / 2.);
  }
  G convex_hull(bool online = false) {
    if (size() < 2)
      return *this;
    sort(ALL(*this));
    G r;
    r.resize((int)size() * 2);
    int k = 0;
    for (int i = 0; i < size(); r[k++] = at(i++))
      while (k > 1 && ccw(r[k - 2], r[k - 1], at(i)) < 1 - online)
        k--;
    int t = k;
    for (int i = (int)size() - 1; i >= 0; r[k++] = at(i--))
      while (k > t && ccw(r[k - 2], r[k - 1], at(i)) < 1 - online)
        k--;
    r.resize(k - 1);
    return r;
  }
  G cut(const L &l) const {
    G g;
    REP(i, size()) {
      const S &s = edge(i);
      if (ccw(l[0], l[1], s[0], 0) >= 0)
        g.push_back(s[0]);
      if (ccw(l[0], l[1], s[0], 0) * ccw(l[0], l[1], s[1], 0) < 0)
        g.push_back(crosspoint(s, l));
    }
    return g;
  }
  G Voronoi(const vector<P> &p, const int t) const {
    G g = *this;
    REP(i, p.size()) if (i != t) {
      const P m = (p[t] + p[i]) * 0.5;
      g = g.cut(L(m, m + (p[i] - p[t]) * P(0, 1)));
    }
    return g;
  }
};
inline P proj(const P &s, const L &t) {
  return t[0] + proj(s - t[0], t[1] - t[0]);
}
inline P reflect(const P &s, const L &t) { return 2. * proj(s, t) - s; }
inline S reflect(const S &s, const L &t) {
  return S(reflect(s[0], t), reflect(s[1], t));
}
BOOL intersect(const S &s, const S &t) {
  const int p = ccw(t[0], t[1], s[0], 1) * ccw(t[0], t[1], s[1], 1);
  const int q = ccw(s[0], s[1], t[0], 1) * ccw(s[0], s[1], t[1], 1);
  return (p > 0 || q > 0) ? FALSE : (!p || !q) ? BORDER : TRUE;
}
BOOL intersect(const S &s, const L &l) {
  if (l.online(s[0]) || l.online(s[1]))
    return BORDER;
  return (sig(outp(l.dir(), s[0] - l[0])) * sig(outp(l.dir(), s[1] - l[0])) <=
          0);
}
R dist2(const L &l, const P &p) {
  return norm(outp(l.dir(), p - l[0])) / norm(l.dir());
}
R dist2(const S &s, const P &p) {
  if (inp(p - s[0], s.dir()) < EPS)
    return norm(p - s[0]);
  if (inp(p - s[1], -s.dir()) < EPS)
    return norm(p - s[1]);
  return dist2((const L &)s, p);
}
R dist2(const S &s, const L &l) {
  return intersect(s, l) ? .0 : min(dist2(l, s[0]), dist2(l, s[1]));
}
R dist2(const S &s, const S &t) {
  return intersect(s, t) ? .0
                         : min(min(dist2(s, t[0]), dist2(t, s[0])),
                               min(dist2(s, t[1]), dist2(t, s[1])));
}
template <class T> R dist2(const G &g, const T &t) {
  R res = INF;
  REP(i, g.size()) res = min(res, dist2(g.edge(i), t));
  return res;
}
template <class S, class T> R dist(const S &s, const T &t) {
  return sqrt(dist2(s, t));
}
inline BOOL intersect(const C &a, const C &b) {
  return less((a.r - b.r) * (a.r - b.r), norm(a - b)) +
         less(norm(a - b), (a.r + b.r) * (a.r + b.r)) - 1;
}
inline BOOL intersect(const C &c, const L &l) {
  return less(dist2(l, c), c.r * c.r);
}
inline BOOL intersect(const C &c, const S &s) {
  int d = less(dist2(s, c), c.r * c.r);
  if (d != TRUE)
    return d;
  int p = c.inside(s[0]), q = c.inside(s[1]);
  return (p < 0 || q < 0) ? BORDER : p & q;
}
inline S crosspoint(const C &c1, const C &c2) {
  if (!intersect(c1, c2))
    return S();
  R d = abs(c1 - c2);
  R x = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
  R h = sqrt(c1.r * c1.r - x * x);
  P u = unit(c2 - c1);
  return S(c1 + u * x + u * P(0, -1) * h, c1 + u * x + u * P(0, 1) * h);
}
inline P crosspoint(const L &l, const L &m) {
  R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);
  if (!sig(abs(A)) && !sig(abs(B)))
    return m[0];
  if (abs(A) < EPS)
    assert(false);
  return m[0] + B / A * (m[1] - m[0]);
}
inline S crosspoint(const C &c, const L &l) {
  R d2 = dist2(l, c);
  if (c.r * c.r + EPS < d2)
    return S();
  P m = proj(c, l);
  P u = unit(l[1] - l[0]);
  R d = sqrt(c.r * c.r - d2);
  return S(m + u * d, m - u * d);
}
inline vector<P> crosspoint(const C &c, const S &s) {
  vector<P> res = crosspoint(c, (const L &)s);
  RREP(i, res.size()) {
    if (inp(res[i] - s[0], s.dir()) * inp(res[i] - s[1], -s.dir()) < EPS)
      res.erase(res.begin() + i);
  }
  return res;
}
inline R commonarea(const C &a, const C &b) {
  if (less(norm(a - b), (a.r - b.r) * (a.r - b.r)) == TRUE)
    return min(a.r * a.r, b.r * b.r) * PI;
  if (less((a.r + b.r) * (a.r + b.r), norm(a - b)) == TRUE)
    return .0;
  double d = abs(a - b);
  double rc = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
  double theta = acos(rc / a.r);
  double phi = acos((d - rc) / b.r);
  return a.r * a.r * theta + b.r * b.r * phi - d * a.r * sin(theta);
}
vector<L> CommonTangent(C c1, C c2) {
  if (c1.r > c2.r)
    swap(c1, c2);
  double d = abs(c1 - c2);
  vector<L> res;
  if (d < EPS)
    return res;
  if (d + EPS > c1.r + c2.r) {
    P crs = (c1 * c2.r + c2 * c1.r) / (c1.r + c2.r);
    double rad = asin(c1.r / abs(crs - c1));
    res.push_back(L(crs, crs + (c1 - crs) * polar(1., rad)));
    res.push_back(L(crs, crs + (c1 - crs) * polar(1., -rad)));
  }
  if (c1.r + d + EPS > c2.r) {
    double rad = 0.5 * PI + asin((c2.r - c1.r) / d);
    P v = unit(c2 - c1) * polar(1., rad);
    if (c1.r + d - EPS < c2.r) {
      res.push_back(L(c1 + v * c1.r, c1 + v * c1.r + (c1 - c2) * P(0, 1)));
    } else {
      res.push_back(L(c1 + v * c1.r, c2 + v * c2.r));
      v = 2. * proj(v, c2 - c1) - v;
      res.push_back(L(c1 + v * c1.r, c2 + v * c2.r));
    }
  }
  return res;
}
struct min_ball {
  P center;
  R radius2;
  min_ball(const vector<P> &p) { FOR(it, p) ps.push_back(*it); }
  min_ball &compile() {
    m = 0;
    center = P(0, 0);
    radius2 = -1;
    make_ball(ps.end());
    return *this;
  }

private:
  list<P> ps;
  list<P>::iterator supp_end;
  int m;
  P v[3], c[3];
  R z[3], r[3];
  void pop() { --m; }
  void push(const P &p) {
    if (m == 0) {
      c[0] = p;
      r[0] = 0;
    } else {
      R e = norm(p - c[m - 1]) - r[m - 1];
      P delta = p - c[0];
      v[m] = p - c[0];
      for (int i = 1; i < m; ++i)
        v[m] -= v[i] * inp(v[i], delta) / z[i];
      z[m] = inp(v[m], v[m]);
      c[m] = c[m - 1] + e * v[m] / z[m] * .5;
      r[m] = r[m - 1] + e * e / z[m] * .25;
    }
    center = c[m];
    radius2 = r[m];
    ++m;
  }
  void make_ball(list<P>::iterator i) {
    supp_end = ps.begin();
    if (m == 3)
      return;
    for (list<P>::iterator k = ps.begin(); k != i;) {
      list<P>::iterator j = k++;
      if (norm(*j - center) > radius2) {
        push(*j);
        make_ball(j);
        pop();
        move_to_front(j);
      }
    }
  }
  void move_to_front(list<P>::iterator j) {
    if (supp_end == j)
      ++supp_end;
    ps.splice(ps.begin(), ps, j);
  }
};
struct Arrangement {
  struct AEdge {
    int u, v, t;
    R cost;
    AEdge(int u = 0, int v = 0, int t = 0, R cost = 0)
        : u(u), v(v), t(t), cost(cost) {}
  };
  typedef vector<vector<AEdge>> AGraph;
  vector<P> p;
  AGraph g;
  Arrangement() {}
  Arrangement(vector<S> seg) {
    int m = seg.size();
    REP(i, m) {
      p.push_back(seg[i][0]);
      p.push_back(seg[i][1]);
      REP(j, i)
      if (sig(outp(seg[i].dir(), seg[j].dir())) &&
          intersect(seg[i], seg[j]) == TRUE)
          p.push_back(crosspoint(seg[i], seg[j]));
    }
    sort(ALL(p));
    UNIQUE(p);
    int n = p.size();
    g.resize(n);
    REP(i, m) {
      S &s = seg[i];
      vector<pair<R, int>> ps;
      REP(j, n) if (s.online(p[j])) ps.emplace_back(norm(p[j] - s[0]), j);
      sort(ALL(ps));
      REP(j, (int)ps.size() - 1) {
        const int u = ps[j].second;
        const int v = ps[j + 1].second;
        g[u].emplace_back(u, v, 0, abs(p[u] - p[v]));
        g[v].emplace_back(v, u, 0, abs(p[u] - p[v]));
      }
    }
  }
  int getIdx(P q) {
    auto it = lower_bound(ALL(p), q);
    if (it == p.end() || *it != q)
      return -1;
    return it - p.begin();
  }
};
struct DualGraph {
  struct DEdge {
    int u, v, f, l;
    R a;
    DEdge(int u, int v, R a) : u(u), v(v), f(0), l(0) {
      while (PI < a)
        a -= 2 * PI;
      while (a < -PI)
        a += 2 * PI;
      this->a = a;
    }
    bool operator==(const DEdge &opp) const { return v == opp.v; }
    bool operator<(const DEdge &opp) const { return a > opp.a; }
    bool operator<(const R &opp) const { return a > opp; }
    friend ostream &operator<<(ostream &os, const DEdge &t) {
      return os << "(" << t.u << "," << t.v << "," << t.a * 180 / PI << ")";
    }
  };
  int n;
  vector<P> p;
  vector<vector<DEdge>> g;
  UnionFind uf;
  DualGraph(const vector<P> &p)
      : p(p), g(p.size()), n(p.size()), uf(p.size()) {}
  void add_edge(const int s, const int t) {
    R a = arg(p[t] - p[s]);
    g[s].emplace_back(s, t, a);
    g[t].emplace_back(t, s, a > 0 ? a - PI : a + PI);
    uf.unionSet(s, t);
  }
  vector<G> poly;
  void add_polygon(int s, int t, R a) {
    auto e = lower_bound(ALL(g[s]), a - EPS);
    if (e == g[s].end())
      e = g[s].begin();
    if (e->f)
      return;
    e->f = 1;
    e->l = t;
    poly[t].push_back(p[s]);
    add_polygon(e->v, t, e->a > 0 ? e->a - PI : e->a + PI);
  }
  void toSpanningTree() {
    vector<pair<R, pii>> e;
    REP(i, n)
    REP(j, i) if (!uf.findSet(i, j))
        e.emplace_back(norm(p[i] - p[j]), pii(i, j));
    sort(ALL(e));
    REP(ii, e.size()) {
      const int i = e[ii].second.first;
      const int j = e[ii].second.second;
      if (uf.findSet(i, j))
        continue;
      const S s(p[i], p[j]);
      if ([&]() {
            REP(k, n) if (i != k && j != k) {
              FOR(it, g[k])
              if (intersect(s, S(p[k], p[it->v])) == TRUE)
                return 0;
            }
            return 1;
          }())
        add_edge(i, j);
    }
  }
  vector<vi> dual() {
    toSpanningTree();
    REP(i, n) {
      sort(ALL(g[i]));
      UNIQUE(g[i]);
    }
    int s = min_element(ALL(p)) - p.begin();
    poly.emplace_back();
    add_polygon(s, poly.size() - 1, -PI * .5);
    REP(i, n) REP(j, g[i].size()) if (!g[i][j].f) {
      poly.emplace_back();
      add_polygon(i, poly.size() - 1, g[i][j].a + 2. * EPS);
    }
    int m = poly.size();
    vector<vi> dg(m, vi(m, 1 << 20));
    REP(i, m) dg[i][i] = 0;
    vector<unordered_map<int, int>> rev(n);
    REP(i, n) REP(j, g[i].size()) {
      int u = i, v = g[i][j].v, l = g[i][j].l;
      if (u > v)
        swap(u, v);
      if (rev[u].find(v) != rev[u].end()) {
        if (l != rev[u][v]) {
          dg[l][rev[u][v]] = 1;
          dg[rev[u][v]][l] = 1;
        }
      } else
        rev[u][v] = l;
    }
    return dg;
  }
};
#undef SELF
#undef at
} // namespace geom
using namespace geom;
namespace std {
bool operator<(const P &a, const P &b) {
  return sig(a.X - b.X) ? a.X < b.X : a.Y < b.Y;
}
bool operator==(const P &a, const P &b) { return !sig(norm(a - b)); }
istream &operator>>(istream &is, P &p) {
  R x, y;
  is >> x >> y;
  p = P(x, y);
  return is;
}
istream &operator>>(istream &is, L &l) {
  l.resize(2);
  return is >> l[0] >> l[1];
}
istream &operator>>(istream &is, C &c) { return is >> (P &)c >> c.r; }
const double B = 500;
const double Z = 1;
ostream &operator<<(ostream &os, const C &c) {
  return os << "circle(" << B + Z * (c.X) << ", " << 1000 - B - Z * (c.Y)
            << ", " << Z * (c.r) << ")";
}
ostream &operator<<(ostream &os, const P &p) { return os << C(p, 2.); }
ostream &operator<<(ostream &os, const S &s) {
  return os << "line(" << B + Z * (s[0].X) << ", " << 1000 - B - Z * (s[0].Y)
            << ", " << B + Z * (s[1].X) << ", " << 1000 - B - Z * (s[1].Y)
            << ")";
}
ostream &operator<<(ostream &os, const G &g) {
  REP(i, g.size()) cout << g.edge(i) << endl;
  return os;
}
} // namespace std
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ios::sync_with_stdio(false);
  while (cin >> n) {
    vector<G> poly(n);
    vector<S> s;
    REP(i, n) {
      int x;
      cin >> x;
      poly[i].resize(x);
      REP(j, x) cin >> poly[i][j];
      REP(j, x) s.push_back(poly[i].edge(j));
    }
    Arrangement arg(s);
    DualGraph dg(arg.p);
    REP(i, arg.g.size()) FOR(e, arg.g[i]) dg.add_edge(e->u, e->v);
    vector<vi> g = dg.dual();
    const auto &area = dg.poly;
    int m = area.size();
    vi level(m, -1);
    level[0] = 0;
    REPS(i, m - 1) {
      level[i] = count_if(ALL(poly), [&](const G &arg) {
        REP(j, area[i].size()) {
          const S &s = area[i].edge(j);
          const P p = (s[0] + s[1]) * .5;
          if (!arg.contains(p))
            return 0;
        }
        return 1;
      });
      if (level[i] == -1)
        assert(false);
    }
    REP(i, m)
    REP(j, i) if (g[i][j] == 1) g[i][j] = g[j][i] = abs(level[i] - level[j]);
    REP(k, m) REP(i, m) REP(j, m) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int q;
    cin >> q;
    REP(i, q) {
      P s, t;
      cin >> s >> t;
      int su = 0, tu = 0;
      REPS(j, m - 1) {
        if (area[j].contains(s))
          su = j;
        if (area[j].contains(t))
          tu = j;
      }
      cout << g[su][tu] << endl;
    }
  }
  return 0;
}
