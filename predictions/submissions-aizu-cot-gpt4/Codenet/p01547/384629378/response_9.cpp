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
  D cross_b_c = cross(b, c);
  D norm_b = norm(b);
  D norm_c = norm(c);
  if (cross_b_c > EPS)
    return +1;
  if (cross_b_c < -EPS)
    return -1;
  if (dot(b, c) < -EPS)
    return +2;
  if (norm_b < norm_c)
    return -2;
  return 0;
}
// rest of the code remains the same until `convexHull` function

VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch;
  ch.resize(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  ch.resize(k - 1);
  return ch;
}
// rest of the code remains the same until `convexCut` function

VP convexCut(const VP &ps, P a1, P a2) {
  int n = ps.size();
  VP ret;
  ret.reserve(n);
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
// rest of the code remains the same until the main function

int main() {
  vector<P> s1, s2;
  int n, m, q;
  scanf("%d", &n);
  VP V[n];
  rep(i, n) {
    scanf("%d", &m);
    D x[m], y[m];
    rep(j, m) {
      scanf("%lf %lf", &x[j], &y[j]);
      V[i].push_back(P(x[j], y[j]));
    }
    // rest of the code
}