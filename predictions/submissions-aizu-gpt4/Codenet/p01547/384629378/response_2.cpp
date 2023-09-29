#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef complex<D> P;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;
#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (abs((n) - (m)) < EPS)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second

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
  sort(all(ps));
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
      ret.pb(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn == -1)
      ret.pb(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  return ret;
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
      V[i].pb(P(x[j], y[j]));
    }
    rep(j, m) {
      s1.pb(P(x[j], y[j]));
      s2.pb(P(x[(j + 1) % m], y[(j + 1) % m]));
    }
  }
  VP convex;
  convex.push_back(P(-200000, -200000));
  convex.push_back(P(200000, -200000));
  convex.push_back(P(200000, 200000));
  convex.push_back(P(-200000, 200000));
  Vcon v;
  v.pb(convex);
  rep(i, s1.size()) {
    Vcon nv;
    rep(j, v.size()) {
      VP cv1 = convexCut(v[j], s1[i], s2[i]);
      if (!cv1.empty() && area(cv1) >= EPS)
        nv.pb(cv1);
      VP cv2 = convexCut(v[j], s2[i], s1[i]);
      if (!cv2.empty() && area(cv2) >= EPS)
        nv.pb(cv2);
    }
    v = nv;
  }
  vector<vector<int>> a(v.size(), vector<int>(v.size(), 1e8));
  rep(i, v.size()) {
    for (int j = i + 1; j < v.size(); j++) {
      rep(k, v[i].size()) {
        rep(l, v[j].size()) {
          if (isecSS(v[i][k], v[i][(k + 1) % v[i].size()], v[j][l],
                     v[j][(l + 1) % v[j].size()])) {
            a[i][j] = a[j][i] = 1;
          }
        }
      }
    }
  }
  rep(i, v.size()) a[i][i] = 0;
  rep(k, v.size()) rep(i, v.size()) rep(j, v.size()) a[i][j] =
      min(a[i][j], a[i][k] + a[k][j]);
  cin >> q;
  while (q--) {
    int A = -1, B = -1;
    D a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    rep(i, v.size()) {
      if (inPolygon(v[i], P(a1, a2))) {
        A = i;
        break;
      }
    }
    rep(i, v.size()) {
      if (inPolygon(v[i], P(b1, b2))) {
        B = i;
        break;
      }
    }
    cout << a[A][B] << endl;
  }
}