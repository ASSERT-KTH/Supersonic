#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define rep(i, n) for (int i = 0; i < (n); i++)
D dot(P a, P b) { return (conj(a)*b).X; }
D cross(P a, P b) { return (conj(a)*b).Y; }
int ccw(P a, P b, P c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;
  if (cross(b,c) < -EPS) return -1;
  if (dot(b,c)   < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}
P crosspointLL(const P &a1, const P &a2, const P &b1, const P &b2) {
  D d1 = cross(b2-b1, b1-a1);
  D d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;
  if (EQ(d2, 0)) assert(false);
  return a1 + d1/d2 * (a2-a1);
}
VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}
int inPolygon(const VP &ps, const P &p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    P a = ps[i] - p;
    P b = ps[(i+1)%n] - p;
    if (a.Y > b.Y) swap(a, b);
    if (a.Y <= 0 && 0 < b.Y && cross(a,b) < 0) in = !in;
    if (EQ(cross(a, b), 0) && dot(a, b) <= 0) return 2;
  }
  return in;
}
VP convexCut(const VP &ps, const P &a1, const P &a2) {
  int n = ps.size();
  VP ret;
  rep(i,n) {
    P a = ps[i], b = ps[(i+1)%n];
    if (ccw(a1, a2, a) != -1) ret.push_back(a);
    if (ccw(a1, a2, a)*ccw(a1, a2, b) < 0)
      ret.push_back(crosspointLL(a1, a2, a, b));
  }
  return ret;
}
D area(const VP &ps) {
  D ret = 0;
  for (int i = 0; i < ps.size(); ++i)
    ret += cross(ps[i], ps[(i+1)%ps.size()]);
  return ret/2;
}
void divide_convex(VP ps, const VP &s1, const VP &s2, Vcon &V) {
  bool flag = false;
  for (int i = 0; i < s1.size(); i++) {
    VP convex_1 = convexCut(ps, s1[i], s2[i]);
    VP convex_2 = convexCut(ps, s2[i], s1[i]);
    if (area(convex_1) < EPS || area(convex_2) < EPS) continue;
    divide_convex(convex_1, s1, s2, V);
    divide_convex(convex_2, s1, s2, V);
    flag = true;
    break;
  }
  if (!flag) V.push_back(ps);
  return;
}
vector<vector<int>> Convex_arrangement(const Vcon &ps) {
  int n = ps.size();
  vector<vector<int>> V(n, vector<int>(n));
  rep(i, n) rep(j, n) V[i][j] = 1e8;
  rep(i, n) {
    for (int j = i+1; j < n; j++) {
      if (abs(area(ps[i]) - area(ps[j])) < EPS) {
        V[i][j] = 1;
        V[j][i] = 1;
      }
    }
  }
  return V;
}
signed main() {
  int n, m, q;
  cin >> n;
  VP V[n];
  rep(i,n) {
    cin >> m;
    rep(j,m) {
      D x, y;
      cin >> x >> y;
      V[i].push_back(P(x, y));
    }
  }
  VP convex;
  convex.push_back(P(-200000, -200000));
  convex.push_back(P(200000, -200000));
  convex.push_back(P(200000, 200000));
  convex.push_back(P(-200000, 200000));
  Vcon v;
  VP s1, s2;
  rep(i,n) rep(j,V[i].size()) {
    s1.push_back(V[i][j]);
    s2.push_back(V[i][(j+1)%V[i].size()]);
  }
  divide_convex(convex, s1, s2, v);
  vector<vector<int>> a = Convex_arrangement(v);
  vector<int> cnt(v.size());
  rep(i, v.size()) {
    rep(j, n) {
      if (inPolygon(V[j], v[i][0])) cnt[i]++;
    }
  }
  rep(i, v.size()) {
    rep(j, v.size()) {
      if (i == j) a[i][j] = 0;
      if (a[i][j] == 1) a[i][j] = abs(cnt[i] - cnt[j]);
    }
  }
  rep(k, v.size()) rep(i, v.size()) rep(j, v.size()) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  cin >> q;
  while (q--) {
    D a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int A, B;
    rep(i, v.size()) {
      if (inPolygon(v[i], P(a1, a2))) A = i;
      if (inPolygon(v[i], P(b1, b2))) B = i;
    }
    cout << a[A][B] << endl;
  }
}
