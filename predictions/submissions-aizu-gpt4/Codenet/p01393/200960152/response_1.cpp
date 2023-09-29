#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef double D;
typedef pair<D, D> pdd;
const D EPS = 1e-8;
const D PI = acos(-1);
int n, k;
pdd p[2000];
vector<pdd> v;
int max_r[2000], max_l[2000];
inline void modify(D &seta) {
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}
inline bool in_upper(const D &seta) { return (EPS < seta && seta < PI - EPS); }
bool comp(const pdd &a, const pdd &b) {
  return abs(a.fs - b.fs) < EPS ? a.sc + EPS < b.sc : a.fs < b.fs;
}
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    D x, y, r;
    cin >> x >> y >> r;
    D d = hypot(x, y), s = atan2(y, x), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.fs >= EPS && tmp.sc <= PI - EPS)
      v.push_back(tmp);
  }
  sort(v.begin(), v.end(), comp);
  v.erase(unique(v.begin(), v.end()), v.end());
  int m = v.size();
  for (int i = 0; i < m; i++) {
    pdd dummy(v[i].sc, 0);
    max_l[i] = upper_bound(v.begin(), v.end(), dummy, comp) - v.begin();
    max_r[i] = max_l[i] - 1;
  }
  vector<vd> dp1(m + 1, vd(k + 1, 0)), dp2 = dp1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
      if (j + 1 <= k) {
        D use = max(dp1[i][j], dp2[i][j]);
        dp1[max_l[i]][j + 1] = max(dp1[max_l[i]][j + 1], use + v[i].sc - v[i].fs);
        if (max_r[i] != i) {
          dp2[max_r[i]][j + 1] =
              max(dp2[max_r[i]][j + 1], use + v[max_r[i]].fs - v[i].fs);
        }
      }
    }
  }
  D ans = 0;
  for (int i = 0; i <= k; i++) ans = max(ans, dp1[m][i]);
  cout << fixed << setprecision(10) << ans / PI << "\n";
}