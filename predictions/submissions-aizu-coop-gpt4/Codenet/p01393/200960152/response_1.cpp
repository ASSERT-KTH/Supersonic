#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define fs first
#define sc second
using namespace std;
typedef double D;
typedef pair<D, D> pdd;
const D EPS = 1e-8;
const D PI = acos(-1);
int n, k;
pdd p[2000];
pdd v[2000];
bool valid[2000];
int max_r[2000], max_l[2000];
inline void modify(D &seta) {
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}
inline bool in_upper(const D &seta) { return (EPS < seta && seta < PI - EPS); }
inline bool comp(const pdd &a, const pdd &b) {
  return abs(a.fs - b.fs) < EPS ? a.sc + EPS < b.sc : a.fs < b.fs;
}
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n >> k;
  int m = 0;
  rep(i, n) {
    D x, y, r;
    cin >> x >> y >> r;
    D d = sqrt(x * x + y * y), s = atan2(y, x), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.fs < EPS && PI - EPS < tmp.sc)
      continue;
    v[m++] = tmp;
  }
  sort(v, v + m, comp);
  rep(i, m) {
    valid[i] = true;
    rep(j, m) {
      if (i == j)
        continue;
      if (v[j].fs - EPS < v[i].fs && v[i].sc < v[j].sc + EPS) {
        valid[i] = false;
        break;
      }
    }
  }
  D dp1[2000][2000], dp2[2000][2000];
  memset(dp1, 0, sizeof dp1);
  memset(dp2, 0, sizeof dp2);
  rep(i, m) if (valid[i]) rep(j, k + 1) {
    dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
    if (j + 1 <= k) {
      D use = max(dp1[i][j], dp2[i][j]);
      int max_l = upper_bound(v, v + m, pdd(v[i].sc, 0), comp) - v;
      dp1[max_l][j + 1] = max(dp1[max_l][j + 1], use + v[i].sc - v[i].fs);
      int max_r = max_l - 1;
      if (max_r != i) {
        dp2[max_r][j + 1] =
            max(dp2[max_r][j + 1], use + v[max_r].fs - v[i].fs);
      }
    }
  }
  D ans = 0;
  rep(i, k + 1) ans = max(ans, dp1[m][i]);
  cout << fixed << setprecision(10) << ans / PI << "\n";
}