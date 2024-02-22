#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

typedef double D;
typedef pair<D, D> pdd;
typedef vector<D> vd;

const D EPS = 1e-8;
const D PI = acos(-1);

int k;
vector<pdd> v;
vector<int> max_l, max_r;

inline void modify(D &seta) {
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}

inline bool in_upper(const D &seta) { return (EPS < seta && seta < PI - EPS); }

inline bool comp(const pdd &a, const pdd &b) {
  return abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  cin >> n >> k;

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
    if (tmp.first < EPS && PI - EPS < tmp.second)
      continue;
    v.push_back(tmp);
  }

  // Optimized sorting algorithm
  vector<int> cnt(2 * n + 1, 0);
  for (const auto& p : v) {
    int idx = static_cast<int>((p.first + PI) / (2 * PI) * (2 * n));
    cnt[idx]++;
  }
  for (int i = 1; i <= 2 * n; i++) {
    cnt[i] += cnt[i - 1];
  }
  vector<pdd> sorted_v(v.size());
  for (int i = v.size() - 1; i >= 0; i--) {
    int idx = static_cast<int>((v[i].first + PI) / (2 * PI) * (2 * n));
    sorted_v[--cnt[idx]] = v[i];
  }
  v = sorted_v;

  int m = v.size();
  max_l.resize(m);
  max_r.resize(m);
  rep(i, m) {
    max_l[i] = upper_bound(v.begin(), v.end(), pdd(v[i].second, 0), comp) - v.begin();
    max_r[i] = max_l[i] - 1;
  }

  // Use a single 2D vector instead of two separate vectors
  vector<vd> dp(m + 1, vd(k + 1, 0));

  rep(i, m) {
    rep(j, k + 1) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= k) {
        D use = max(dp[i][j], dp[i][j]);
        dp[max_l[i]][j + 1] = max(dp[max_l[i]][j + 1], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp[max_r[i]][j + 1] = max(dp[max_r[i]][j + 1], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }

  D ans = 0;
  rep(i, k + 1) ans = max(ans, dp[m][i]);

  // Avoid unnecessary floating point calculations
  cout << fixed << setprecision(10) << ans << "\n";
}