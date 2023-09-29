#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
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
  if (cross(b, c) > EPS)
    return +1;
  if (cross(b, c) < -EPS)
    return -1;
  if (dot(b, c) < -EPS)
    return +2;
  if (norm(b) < norm(c))
    return -2;
  return 0;
}
bool isparallel(L a, L b) {
  return cross(a.first - a.second, b.first - b.second) == 0.0;
}
bool isecLP(P a1, P a2, P b) { return abs(ccw(a1, a2, b)) != 1; }
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2 - a1, b2 - b1, 0) || isecLP(a1, b1, b2);
}
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS;
}
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
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
  rep(i,
      n) if (ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1) return false;
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
    if ((a.Y * b.Y < 0 || (a.Y * b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0))
      in = !in;
  }
  return in;
}
VP convexCut(const VP &ps, P a1, P a2) {
  int n = ps.size();
  VP ret;
  rep(i, n) {
    int ccwc = ccw(a1, a2, ps[i]);
    if (ccwc != -1)
      ret.push_back(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn == -1)
      ret.push_back(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  return ret;
}
D area(const VP &);
bool isec_CS(const VP &ps, P a1, P a2) {
  rep(i, ps.size()) {
    if (isecLS(ps[i], ps[(i + 1) % ps.size()], a1, a2))
      return true;
  }
  return false;
}
void divide_convex(VP ps, const VP &s1, const VP &s2, Vcon &V) {
  bool flag = false;
  for (int i = 0; i < s1.size(); i++) {
    VP convex_1 = convexCut(ps, s1[i], s2[i]);
    VP convex_2 = convexCut(ps, s2[i], s1[i]);
    if (area(convex_1) < EPS || area(convex_2) < EPS)
      continue;
    divide_convex(convex_1, s1, s2, V);
    divide_convex(convex_2, s1, s2, V);
    flag = true;
    break;
  }
  if (!flag)
    V.push_back(ps);
  return;
}
bool isecCC(VP a1, VP a2) {
  rep(i, a1.size()) {
    rep(j, a2.size()) {
      P e1 = a1[i];
      P e2 = a1[(i + 1) % a1.size()];
      P e3 = a2[j];
      P e4 = a2[(j + 1) % a2.size()];
      if (abs(e1 - e3) < EPS && abs(e2 - e4) < EPS)
        return 1;
      if (abs(e1 - e4) < EPS && abs(e2 - e3) < EPS)
        return 1;
    }
  }
  return 0;
}
vector<vector<int>> Convex_arrangement(const Vcon &ps) {
  int n = ps.size();
  vector<vector<int>> V(n, vector<int>(n));
  rep(i, n) rep(j, n) V[i][j] = 1e8;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      if (isecCC(ps[i], ps[j])) {
        V[i][j] = 1;
        V[j][i] = 1;
      }
    }
  }
  return V;
}
D area(const VP &ps) {
  D a = 0;
  rep(i, ps.size()) a += cross(ps[i], ps[(i + 1) % ps.size()]);
  return a / 2;
}
bool con_in_con(VP a1, VP a2) {
  int p = 0;
  rep(j, a2.size()) {
    int sum = 0, f = 0;
    rep(i, a1.size()) {
      if (isecSP(a1[i], a1[(i + 1) % a1.size()], a2[j]))
        goto L1;
      if (isecSS(a1[i], a1[(i + 1) % a1.size()], a2[j], P(1000007, 41321))) {
        sum++;
        f++;
      }
    }
    p++;
    if ((sum % 2))
      return 1;
    if ((sum % 2 == 0))
      return 0;
  L1:;
    sum = f = 0;
    rep(i, a1.size()) {
      if (isecSP(a1[i], a1[(i + 1) % a1.size()],
                 (a2[j] + a2[(j + 1) % a2.size()]) / 2.0))
        goto L;
      if (isecSS(a1[i], a1[(i + 1) % a1.size()],
                 (a2[j] + a2[(j + 1) % a2.size()]) / 2.0, P(1000007, 41321))) {
        sum++;
        f++;
      }
    }
    p++;
    if ((sum % 2))
      return 1;
    if ((sum % 2 == 0))
      return 0;
    sum = 0;
  L:;
  }
  return !p;
}
signed main() {
  vector<P> s1, s2;
  int n, m, q;
  cin >> n;
  VP V[n];
  rep(i, n) {
    cin >> m;
    D x[m], y[m];
    rep(j, m) {
      cin >> x[j] >> y[j];
      V[i].push_back(P(x[j], y[j]));
    }
    rep(j, m) {
      s1.push_back(P(x[j], y[j]));
      s2.push_back(P(x[(j + 1) % m], y[(j + 1) % m]));
    }
  }
  VP convex;
  convex.push_back(P(-200000, -200000));
  convex.push_back(P(200000, -200000));
  convex.push_back(P(200000, 200000));
  convex.push_back(P(-200000, 200000));
  Vcon v;
  divide_convex(convex, s1, s2, v);
  vector<vector<int>> a = Convex_arrangement(v);
  int cnt[v.size()] = {};
  rep(i, v.size()) {
    rep(j, n) {
      if (con_in_con(V[j], v[i])) {
        cnt[i]++;
      }
    }
  }
  rep(i, v.size()) {
    rep(j, v.size()) {
      if (i == j)
        a[i][j] = 0;
      if (a[i][j] == 1) {
        a[i][j] = abs(cnt[i] - cnt[j]);
      }
    }
  }
  rep(k, v.size()) rep(i, v.size()) rep(j, v.size()) a[i][j] =
      min(a[i][j], a[i][k] + a[k][j]);
  cin >> q;
  while (q--) {
    int A = 1e9, B = 1e9;
    D a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    rep(i, v.size()) {
      if (inPolygon(v[i], P(a1, a2))) {
        A = i;
        if (inPolygon(v[i], P(a1, a2)) == 1)
          break;
      }
    }
    rep(i, v.size()) {
      if (inPolygon(v[i], P(b1, b2))) {
        B = i;
        if (inPolygon(v[i], P(b1, b2)) == 1)
          break;
      }
    }
    cout << a[A][B] << endl;
  }
}
