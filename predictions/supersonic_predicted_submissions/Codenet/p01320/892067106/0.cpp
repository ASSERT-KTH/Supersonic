#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
namespace geom {
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
enum { TRUE = 1, FALSE = 0, BORDER = -1 };
typedef int BOOL;
typedef double R;
const R INF = 1e8;
R EPS = 1e-6;
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
    return !sig(outp(p - at(0), dir())) && inp(p - at(0), dir()) > -EPS &&
                   inp(p - at(1), -dir()) > -EPS
               ? TRUE
               : FALSE;
    return !sig(abs(at(0) - p) + abs(at(1) - p) - abs(at(0) - at(1)));
  }
};
P crosspoint(const L &l, const L &m);
struct G : public vector<P> {
  G(size_type size = 0) : vector(size) {}
  S edge(int i) const { return S(at(i), at(i + 1 == size() ? 0 : i + 1)); }
};
inline BOOL intersect(const S &s, const L &l) {
  return (sig(outp(l.dir(), s[0] - l[0])) * sig(outp(l.dir(), s[1] - l[0])) <=
          0);
}
inline P crosspoint(const L &l, const L &m) {
  R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);
  if (!sig(abs(A)) && !sig(abs(B)))
    return m[0];
  if (abs(A) < EPS)
    assert(false);
  return m[0] + B / A * (m[1] - m[0]);
}
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
  DualGraph(const vector<P> &p) : p(p), g(p.size()), n(p.size()) {}
  void add_edge(const int s, const int t) {
    R a = arg(p[t] - p[s]);
    g[s].emplace_back(s, t, a);
    g[t].emplace_back(t, s, a > 0 ? a - PI : a + PI);
  }
  void add_polygon(int s, G &t, R a) {
    auto e = lower_bound(ALL(g[s]), a - EPS);
    if (e == g[s].end())
      e = g[s].begin();
    if (e->f)
      return;
    e->f = 1;
    t.push_back(p[s]);
    add_polygon(e->v, t, e->a > 0 ? e->a - PI : e->a + PI);
  }
  G dual() {
    REP(i, n) {
      sort(ALL(g[i]));
      UNIQUE(g[i]);
    }
    int s = min_element(ALL(p)) - p.begin();
    G poly;
    add_polygon(s, poly, -PI * (R).5);
    return poly;
  }
};
#undef SELF
#undef at
} // namespace geom
using namespace geom;
namespace std {
bool operator<(const P &a, const P &b) {
  return sig(a.X - b.X) ? a.X < b.X : a.Y + EPS < b.Y;
}
bool operator==(const P &a, const P &b) { return abs(a - b) < EPS; }
istream &operator>>(istream &is, P &p) {
  R x, y;
  is >> x >> y;
  p = P(x, y);
  return is;
}
} // namespace std
int n, m, k;
struct MSQ : public G {
  MSQ() {}
  vector<P> p;
  vector<S> s;
  int m, k;
  MSQ(int m, int k) : m(m), k(k) {
    REP(i, m) p.push_back(polar((R)1, 2 * PI * i / m + PI * (R).5));
    REP(i, m) s.emplace_back(p[i], p[(i + k) % m]);
    Arrangement a(s);
    DualGraph dg(a.p);
    REP(i, a.g.size()) REP(j, a.g[i].size()) {
      int u = a.g[i][j].u;
      int v = a.g[i][j].v;
      if (u < v)
        dg.add_edge(u, v);
    }
    (G &)(*this) = dg.dual();
    reverse(this->begin(), this->end());
  }
  void copy(R r, P c, MSQ &msq) const {
    msq.resize(size());
    msq.p.resize(p.size());
    msq.s.resize(s.size());
    msq.m = m;
    msq.k = k;
    REP(i, size()) msq[i] = at(i) * r + c;
    REP(i, p.size()) msq.p[i] = p[i] * r + c;
    REP(i, s.size()) msq.s[i] = S(msq.p[i], msq.p[(i + k) % m]);
  }
  S segment(int i) const { return s[i]; }
};
int convex_contains(const MSQ &msq, const P &g, const P &p) {
  const int n = msq.size();
  int a = 0, b = n;
  const P pg = p - g;
  while (a + 1 < b) {
    int c = (a + b) / 2;
    if (outp(msq[a] - g, pg) > 0 && outp(msq[c] - g, pg) < 0)
      b = c;
    else
      a = c;
  }
  b %= n;
  if (outp(msq[a] - p, msq[b] - p) < -EPS)
    return 0;
  return 1;
}
bool check(const MSQ &temp, R r, const vector<P> &shoolack, int i, int j) {
  MSQ msq;
  L l = temp.segment(j);
  P gp = shoolack[i] - l[0] * r;
  temp.copy(r, gp, msq);
  vector<P> p;
  P b(-INF, -INF), u(+INF, +INF);
  REP(i, n) {
    L l2(shoolack[i], shoolack[i] + l.dir());
    int f = 0;
    P ll(INF, INF), rr(-INF, -INF);
    REP(j, m) {
      const S s = msq.segment(j);
      if (intersect(s, l2)) {
        if (sig(outp(s.dir(), l2.dir()))) {
          const P q = crosspoint(s, l2) - l2[0];
          p.push_back(q);
          ll = min(ll, q);
          rr = max(rr, q);
        }
        f = 1;
      }
    }
    u = min(rr, u);
    b = max(ll, b);
    if (!f)
      return false;
  }
  FOR(q, p) {
    if (*q < b || u < *q)
      continue;
    if ([&]() {
          REP(i, n) if (!convex_contains(msq, gp, shoolack[i] + *q)) return 0;
          return 1;
        }())
      return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> m >> k, n) {
    MSQ temp(m, k);
    vector<P> shoolack(n);
    REP(i, n) cin >> shoolack[i];
    R best = 2000;
    REP(i, n) REP(j, m) {
      if (!check(temp, best - EPS, shoolack, i, j))
        continue;
      R l = EPS, r = best;
      REP(itr, 50) {
        R m = (l + r) * (R).5;
        if (check(temp, m, shoolack, i, j))
          r = m;
        else
          l = m;
      }
      best = r;
    }
    printf("%.10f\n", (double)best);
  }
  return 0;
}
