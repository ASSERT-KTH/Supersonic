#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;
#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (abs((n) - (m)) < EPS)
D dot(P a, P b) { return (conj(a) * b).X; }
D cross(P a, P b) { return (conj(a) * b).Y; }
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  D cr = cross(b, c);
  if (cr > EPS) return +1;
  if (cr < -EPS) return -1;
  if (dot(b, c) < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}
bool isparallel(L a, L b) {
  return abs(cross(a.first - a.second, b.first - b.second)) < EPS;
}
bool isecLP(P a1, P a2, P b) { return abs(ccw(a1, a2, b)) != 1; }
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2 - a1, b2 - b1, 0) || isecLP(a1, b1, b2);
}
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < -EPS;
}
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 && ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
}
bool isecSP(P a1, P a2, P b) {
  return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS;
}
P crosspointLL(P a1, P a2, P b1, P b2) {
  D d1 = cross(b2 - b1, b1 - a1);
  D d2 = cross(b2 - b1, a2 - a1);
  if (EQ(d1, 0) && EQ(d2, 0))
    return a1;
  if (EQ(d2, 0))
    throw "kouten ga nai";
  return a1 + d1 / d2 * (a2 - a1);
}
namespace std {
bool operator<(const P a, const P b) {
  return a.X != b.X ? a.X < b.X : a.Y < b.Y;
}
} // namespace std
VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  ch.resize(k - 1);
  return ch;
}
bool isCcwConvex(const VP &ps) {
  int n = ps.size();
  rep(i, n) if (ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1) return false;
  return true;
}
int inConvex(P p, const VP &ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep(i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc)
      return 2;
    if (ccwc != dir)
      return 0;
  }
  return 1;
}
int inPolygon(const VP &ps, P p) {
  int n = ps.size();
  bool in = false;
  rep(i, n) {
    P a = ps[i] - p;
    P b = ps[(i + 1) % n] - p;
    if (EQ(cross(a, b), 0) && LE(dot(a, b), 0))
      return 2;
    if (a.Y > b.Y)
      swap(a, b);
    if ((a.Y * b.Y < 0 || (a.Y * b.Y <