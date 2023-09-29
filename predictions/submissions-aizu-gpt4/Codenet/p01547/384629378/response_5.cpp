#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <complex>
#define rep(i, n) for (int i = 0; i < (n); i++)
const double EPS = 1e-7;
typedef double D;
typedef std::complex<D> P;
typedef std::pair<P, P> Line;
typedef std::vector<P> VP;
typedef std::vector<VP> Vcon;
#define X real()
#define Y imag()
#define EQ(n, m) (std::abs((n) - (m)) < EPS)

D cross(const P& a, const P& b) { return a.X * b.Y - a.Y * b.X; }
D dot(const P& a, const P& b) { return a.X * b.X + a.Y * b.Y; }

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS) return +1;
  if (cross(b, c) < -EPS) return -1;
  if (dot(b, c) < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

P crosspointLL(const P& a1, const P& a2, const P& b1, const P& b2) {
  D d1 = cross(b2 - b1, b1 - a1);
  D d2 = cross(b2 - b1, a2 - a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1; 
  if (EQ(d2, 0)) throw "kouten ga nai";
  return a1 + d1 / d2 * (a2 - a1);
}

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

VP convexCut(const VP& ps, P a1, P a2) {
  int n = ps.size();
  VP ret;
  rep(i, n) {
    int ccwc = ccw(a1, a2, ps[i]);
    if (ccwc != -1) ret.push_back(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn == -1) ret.push_back(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  return ret;
}

void divide_convex(VP ps, const VP& s1, const VP& s2, Vcon& V) {
  bool flag = false;
  for (int i = 0; i < s1.size(); i++) {
    VP convex_1 = convexCut(ps, s1[i], s2[i]);
    VP convex_2 = convexCut(ps, s2[i], s1[i]);
    if (!convex_1.empty() || !convex_2.empty()) continue;
    divide_convex(convex_1, s1, s2, V);
    divide_convex(convex_2, s1, s2, V);
    flag = true;
    break;
  }
  if (!flag) V.push_back(ps);
}

bool isecSS(const P& a1, const P& a2, const P& b1, const P& b2) {
  return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
}

bool isecSP(const P& a1, const P& a2, const P& b) {
  return std::abs(a1 - b) + std::abs(a2 - b) - std::abs(a2 - a1) < EPS;
}

bool con_in_con(VP a1, VP a2) {
  rep(j, a2.size()) {
    int sum = 0, f = 0;
    rep(i, a1.size()) {
      if (isecSP(a1[i], a1[(i + 1) % a1.size()], a2[j])) goto L1;
      if (isecSS(a1[i], a1[(i + 1) % a1.size()], a2[j], P(1000007, 41321))) sum++, f++;
    }
    if ((sum % 2)) return 1;
    if ((sum % 2 == 0)) return 0;
    L1:
    sum = f = 0;
    rep(i, a1.size()) {
      if (isecSP(a1[i], a1[(i + 1) % a1.size()], (a2[j] + a2[(j + 1) % a2.size()]) / 2.0)) goto L;
      if (isecSS(a1[i], a1[(i + 1) % a1.size()], (a2[j] + a2[(j + 1) % a2.size()]) / 2.0, P(1000007, 41321))) sum++, f++;
    }
    if ((sum % 2)) return 1;
    if ((sum % 2 == 0)) return 0;
    L:;
  }
  return false;
}

int inPolygon(const VP& ps, P p) {
  int n = ps.size();
  bool in = false;
  rep(i, n) {
    P a = ps[i] - p;
    P b = ps[(i + 1) % n] - p;
    if (EQ(cross(a, b), 0) && dot(a, b) <= EPS) return 2;
    if (a.Y > b.Y) std::swap(a, b);
    if ((a.Y * b.Y < 0 || (a.Y * b.Y < EPS && b.Y > EPS)) && cross(a, b) < EPS) in = !in;
  }
  return in;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, q;
  std::cin >> n;
  VP V[n];
  rep(i, n) {
    std::cin >> m;
    D x[m], y[m];
    rep(j, m) {
      std::cin >> x[j] >> y[j];
      V[i].push_back(P(x[j], y[j]));
    }
  }
  std::cin >> q;
  while (q--) {
    D a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    int A = -1, B = -1;
    rep(i, n) {
      if (inPolygon(V[i], P(a1, a2)) && A == -1) A = i;
      if (inPolygon(V[i], P(b1, b2)) && B == -1) B = i;
    }
    std::cout << (con_in_con(V[A], V[B]) ? "YES\n" : "NO\n");
  }
  return 0;
}