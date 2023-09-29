#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define fs first
#define sc second
using namespace std;
typedef double D;
typedef pair<D, D> pdd;
typedef vector<D> vd;
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
inline bool comp(const pdd &a, const pdd &b) {
  return abs(a.fs - b.fs) < EPS ? a.sc + EPS < b.sc : a.fs < b.fs;
}
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n >> k;
  vector<pdd> v1(n);
  rep(i, n) {
    D x, y, r;
    cin >> x >> y >> r;
    complex<D> c(x, y);
    D d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.fs < EPS && PI - EPS < tmp.sc)
      continue;
    v1[i] = tmp;
  }
  sort(v1.begin(), v1.end(), comp);
  vector<pdd> v2;
  for(int i = 0; i < n; i++) {
      if(v1[i] == make_pair(0.0, 0.0)) continue;
      
      if(v2.empty() || v2.back().sc < v1[i].fs - EPS) {
          v2.push_back(v1[i]);
      } else {
          v2.back().sc = max(v2.back().sc, v1[i].sc);
      }
  }
  int m = v2.size();
  rep(i, m) {
    pdd dummy(v2[i].sc, 0);
    max_l[i] = upper_bound(v2.begin(), v2.end(), dummy, comp) - v2.begin();
    max_r[i] = max_l[i] - 1;
  }
  vector<vd> dp1(m + 1, vd(k + 1, 0)), dp2 = dp1;
  rep(i, m) rep(j, k + 1) {
    dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
    if (j + 1 <= k) {
      D use = max(dp1[i][j], dp2[i][j]);
      dp1[max_l[i]][j + 1] = max(dp1[max_l[i]][j + 1], use + v2[i].sc - v2[i].fs);
      if (max_r[i] != i) {
        dp2[max_r[i]][j + 1] =
            max(dp2[max_r[i]][j + 1], use + v2[max_r[i]].fs - v2[i].fs);
      }
    }
  }
  D ans = 0;
  rep(i, k + 1) ans = max(ans, dp1[m][i]);
  cout << fixed << setprecision(10) << ans / PI << "\n";
}
