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
vector<pdd> bounds;
vector<int> ids;
int max_r[2000], max_l[2000];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n >> k;
  rep(i, n) {
    D x, y, r;
    cin >> x >> y >> r;
    complex<D> c(x, y);
    D d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    bounds.push_back({start, end});
    pdd tmp = pdd(in_upper(end) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.fs < EPS && tmp.sc > PI - EPS)
      continue;
    v.push_back(tmp);
  }
  int m = v.size();
  ids.resize(m);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int a, int b) {
    return abs(v[a].fs - v[b].fs) < EPS ? v[a].sc + EPS < v[b].sc : v[a].fs < v[b].fs;
  });
  rep(i, m) {
    pdd dummy(v[ids[i]].sc, 0);
    max_l[i] = upper_bound(ids.begin(), ids.end(), dummy, [&](int a, const pdd &b) {
      return v[a].fs < b.fs;
    }) - ids.begin();
    max_r[i] = max_l[i] - 1;
  }
  vector<vd> dp1(m + 1, vd(k + 1, 0));
  vector<vd> dp2 = dp1;
  rep(i, m) rep(j, k + 1) {
    dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
    if (j + 1 <= k) {
      D use = max(dp1[i][j], dp2[i][j]);
      dp1[max_l[i]][j + 1] = max(dp1[max_l[i]][j + 1], use + v[ids[i]].sc - v[ids[i]].fs);
      if (max_r[i] != i) {
        dp2[max_r[i]][j + 1] =
            max(dp2[max_r[i]][j + 1], use + v[ids[max_r[i]]].fs - v[ids[i]].fs);
      }
    }
  }
  D ans = 0;
  rep(i, k + 1) ans = max(ans, dp1[m][i]);
  cout << fixed << setprecision(10) << ans / PI << "\n";
}