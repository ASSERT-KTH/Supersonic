#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i, a, b) for (ll i = a; i < ll(b); i++)
#define rep(i, b) loop(i, 0, b)
#define each(e, c) for (auto &e : c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#ifdef DEBUG
#define dump(...)                                                              \
  (cerr << #__VA_ARGS__ << " = " << (DUMP(), __VA_ARGS__).str() << " ["        \
        << __LINE__ << "]" << endl)
struct DUMP : ostringstream {
  template <class T> DUMP &operator,(const T &t) {
    if (this->tellp())
      *this << ", ";
    *this << t;
    return *this;
  }
};
#else
#define dump(...)
#endif
template <class T> ostream &operator<<(ostream &os, vector<T> const &v) {
  rep(i, v.size()) os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  return os;
}
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define curr(g, i) g[i]
#define next(g, i) g[(i + 1) % g.size()]
#define self (*this)
typedef long double R;
const R eps = 1e-10;
const R inf = 1e12;
const R pi = acos(-1);
typedef complex<R> P;
R arg(P a, P b, P c) {
  R th = arg((a - b) / (c - b));
  return th > 0 ? th : th + 2 * pi;
}
bool comp_x(P const &a, P const &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
bool comp_y(P const &a, P const &b) {
  return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
}
P CENTER = P();
bool comp_arg(P const &a, P const &b) {
  return arg(a, CENTER, CENTER + (R)1.) < arg(b, CENTER, CENTER + (R)1.);
}
namespace std {
bool operator<(P const &a, P const &b) { return comp_x(a, b); }
} // namespace std
R cross(P const &a, P const &b) { return imag(conj(a) * b); }
R dot(P const &a, P const &b) { return real(conj(a) * b); }
struct L : public vector<P> {
  L(P const &a = P(), P const &b = P()) {
    push_back(a);
    push_back(b);
  }
  L(R a, R b, R c) {
    if (fabs(a) < eps)
      self = L(P(0, -c / b), P(1, -c / b));
    else if (fabs(b) < eps)
      self = L(P(-c / a, 0), P(-c / a, 1));
    else
      self = L(P(-c / a, 0), P(0, -c / b));
  }
  P vec() const { return self[1] - self[0]; }
};
struct S : public vector<P> {
  S(P const &a = P(), P const &b = P()) {
    push_back(a);
    push_back(b);
  }
  L line() const { return L(self[0], self[1]); }
  P vec() const { return line().vec(); }
  R len() const { return abs(vec()); }
};
typedef vector<P> G;
struct C {
  P p;
  R r;
  C(P const &p = P(), R r = 0) : p(p), r(r) {}
};
enum { CCW = +1, CW = -1, CAB = +2, ABC = -2, SEG = 0 };
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0)
    return CCW;
  if (cross(b, c) < 0)
    return CW;
  if (dot(b, c) < 0)
    return CAB;
  if (norm(b) < norm(c))
    return ABC;
  return SEG;
}
R area(C const &c) { return pi * c.r * c.r; }
R area(G const &g) {
  R res = 0;
  int n = g.size();
  rep(i, n) res += cross(g[i], g[(i + 1) % n]);
  return abs(res) / 2;
}
R heron(R a, R b, R c) {
  R s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
P biased_center(P const &a, P const &b, P const &c, R wa, R wb, R wc) {
  return (wa * a + wb * b + wc * c) / (wa + wb + wc);
}
P gravity_center(P const &a, P const &b, P const &c) {
  return biased_center(a, b, c, 1, 1, 1);
}
P inner_center(P const &a, P const &b, P const &c) {
  R la = abs(b - c), lb = abs(c - a), lc = abs(a - b);
  return biased_center(a, b, c, la, lb, lc);
}
P circumcenter(P const &a, P const &b, P const &c) {
  R sa = sin(2 * arg(c, a, b)), sb = sin(2 * arg(a, b, c)),
    sc = sin(2 * arg(b, c, a));
  return biased_center(a, b, c, sa, sb, sc);
}
P orthocenter(P const &a, P const &b, P const &c) {
  if (abs(arg(c, a, b)) == pi)
    return a;
  if (abs(arg(a, b, c)) == pi)
    return b;
  if (abs(arg(b, c, a)) == pi)
    return c;
  R ta = tan(arg(c, a, b)), tb = tan(arg(a, b, c)), tc = tan(arg(b, c, a));
  return biased_center(a, b, c, ta, tb, tc);
}
P excenter(P const &a, P const &b, P const &c) {
  R sa = sin(arg(c, a, b)), sb = sin(arg(a, b, c)), sc = sin(arg(b, c, a));
  return biased_center(a, b, c, -sa, sb, sc);
}
bool col(L const &l, L const &m) {
  return abs(cross(l.vec(), m.vec())) > eps ||
         abs(cross(l.vec(), m[0] - l[0])) < eps;
}
bool col(L const &l, S const &s) {
  return cross(l.vec(), s[0] - l[0]) * cross(l.vec(), s[1] - l[0]) < eps;
}
bool col(S const &s, L const &l) { return col(l, s); }
bool col(L const &l, P const &p) {
  return abs(cross(l[1] - p, l[0] - p)) < eps;
}
bool col(P const &p, L const &l) { return col(l, p); }
bool col(const S &s, const S &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool col(const S &s, const P &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < eps;
}
int col(const C &c1, const C &c2) {
  R d = abs(c1.p - c2.p), r1 = c1.r, r2 = c2.r;
  if (r1 + r2 < d)
    return 0;
  if (abs(r1 + r2 - d) < eps)
    return 1;
  if (abs(d - abs(r1 - r2)) < eps)
    return -1;
  if (d < r1 - r2)
    return +3;
  if (d < r2 - r1)
    return -3;
  return 2;
}
P proj(L const &l, P const &p) {
  R t = dot(p - l[0], l.vec()) / norm(l.vec());
  return l[0] + t * (l.vec());
}
P proj(P const &p, L const &l) { return proj(l, p); }
P refl(L const &l, P const &p) { return p + (R)2 * (proj(l, p) - p); }
P refl(P const &p, L const &l) { return refl(l, p); }
R dist(P const &p, P const &q) { return abs(p - q); }
R dist(L const &l, P const &p) { return abs(p - proj(l, p)); }
R dist(P const &p, L const &l) { return dist(l, p); }
R dist(L const &l, L const &m) { return col(l, m) ? 0 : dist(l, m[0]); }
R dist(L const &l, S const &s) {
  return col(l, s) ? 0 : min(dist(l, s[0]), dist(l, s[1]));
}
R dist(S const &s, L const &l) { return dist(l, s); }
R dist(S const &s, P const &p) {
  P const r = proj(s.line(), p);
  return col(s, r) ? abs(r - p) : min(abs(s[0] - p), abs(s[1] - p));
}
R dist(P const &p, S const &s) { return dist(s, p); }
R dist(S const &s, S const &t) {
  return col(s, t) ? 0
                   : min(min(min(dist(s, t[0]), dist(s, t[1])), dist(t, s[0])),
                         dist(t, s[1]));
}
vector<P> hit(L const &l, L const &m) {
  R A = cross(l.vec(), m.vec());
  R B = cross(l.vec(), l[1] - m[0]);
  if (abs(A) < eps && abs(B) < eps)
    return {m[0]};
  if (abs(A) < eps)
    return G();
  return {m[0] + B / A * (m.vec())};
}
vector<P> hit(S const &s, S const &t) {
  return col(s, t) ? hit(s.line(), t.line()) : G();
}
vector<P> hit(L const &l, S const &s) {
  return col(l, s) ? hit(l, s.line()) : G();
}
vector<P> hit(S const &s, L const &l) { return hit(l, s); }
vector<P> hit(C const &c, L const &l) {
  R d = dist(l, c.p);
  if (fabs(d - c.r) < eps)
    return {proj(l, c.p)};
  if (d > c.r)
    return G();
  P h = proj(l, c.p);
  P u = sqrt(c.r * c.r - d * d) * (l.vec()) / abs(l.vec());
  return {h + u, h - u};
}
vector<P> hit(C const &c, S const &s) {
  G cps = hit(c, s.line()), res;
  for (const P &p : cps)
    if (col(s, p))
      res.push_back(p);
  return res;
}
vector<P> hit(C const &c1, C const &c2) {
  if (abs(c1.p - c2.p) < 0)
    return G();
  int i = col(c1, c2);
  if (i == 0 || abs(i) == 3)
    return G();
  R r1 = c1.r, r2 = c2.r, d = abs(c1.p - c2.p);
  if (i == 1)
    return {c1.p + (c2.p - c1.p) * r1 / d};
  P p = c1.p - c2.p;
  R A = -2. * p.real(), B = 2 * p.imag();
  R C = norm(c1.p) - norm(c2.p) - r1 * r1 + r2 * r2;
  return hit(c1, L(A, B, C));
}
vector<P> hit(C const &c, G const &g) {
  vector<P> res;
  int n = g.size();
  rep(i, n) for (P const &p : hit(c, S(g[i], g[(i + 1) % n]))) res.push_back(p);
  return res;
}
C min_ball(G const &g) {
  int n = g.size();
  if (n == 1)
    return C(g[0], 0);
  if (n == 2)
    return C((g[0] + g[1]) / (R)2, abs((g[0] + g[1]) / (R)2 - g[0]));
  P c = (g[0] + g[n / 3] + g[n / 3 * 2]) / (R)3;
  R r = 1.0;
  rep(i, 1000) {
    R d = 0;
    int x = 0;
    rep(j, n) {
      if (d < abs(g[j] - c)) {
        d = abs(g[j] - c);
        x = j;
      }
    }
    c += (g[x] - c) * r;
    if (i & 2)
      r *= 0.8;
  }
  R d = -1;
  int x = 0;
  rep(i, n) {
    if (d < abs(c - g[i])) {
      d = abs(c - g[i]);
      x = i;
    }
  }
  return C(c, abs(c - g[x]));
}
int n, m;
R r[111], mb[111];
vi ans;
bool used[111];
bool chk(int s) {
  vi b;
  rep(i, n) if (!used[i]) b.eb(r[i]);
  vector<R> a;
  loop(i, s, m) a.eb(mb[i]);
  sort(all(a));
  sort(all(b));
  int last = -1;
  rep(i, a.size()) {
    bool found = false;
    loop(j, last + 1, b.size()) {
      if (a[i] < b[j] + eps) {
        found = true;
        last = j;
        break;
      }
    }
    if (!found)
      return false;
  }
  return true;
}
int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  while (cin >> n >> m) {
    ans.clear();
    rep(i, n) cin >> r[i];
    rep(i, m) {
      int k;
      cin >> k;
      G g(k);
      rep(j, k) {
        R x, y;
        cin >> x >> y;
        g[j] = P(x, y);
      }
      mb[i] = min_ball(g).r;
    }
    rep(i, m) used[i] = false;
    bool f = true;
    rep(i, m) {
      bool found = false;
      rep(j, n) {
        if (used[j])
          continue;
        if (!(mb[i] < r[j] + eps))
          continue;
        used[j] = true;
        if (chk(i + 1)) {
          ans.push_back(j);
          found = true;
          break;
        }
        used[j] = false;
      }
      if (!found) {
        f = false;
        break;
      }
    }
    if (f) {
      rep(i, m) cout << ans[i] + 1 << "\n";
    } else
      cout << "NG" << endl;
  }
}
