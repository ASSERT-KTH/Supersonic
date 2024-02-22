#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>

using namespace std;

using D = double;
using pdd = pair<D, D>;
using vd = vector<D>;

const D EPS = 1e-8;
const D PI = acos(-1);

inline void modify(D& seta) {
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}

inline bool in_upper(const D& seta) {
  return (EPS < seta && seta < PI - EPS);
}

inline bool comp(const pdd& a, const pdd& b) {
  return abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<pdd> p(n);
  vector<pdd> v;

  for (int i = 0; i < n; i++) {
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

  sort(v.begin(), v.end(), comp);

  vector<pdd> filtered;
  int j = 0;

  for (int i = 0; i < v.size(); i++) {
    if (j == i || v[j].second + EPS < v[i].first) {
      filtered.push_back(v[i]);
      j = i;
    }
  }

  int m = filtered.size();
  vector<vd> dp1(m + 1, vd(k + 1)), dp2(m + 1, vd(k + 1));

  for (int i = 0; i < m; i++) {
    pdd dummy(filtered[i].second, 0);
    auto it = upper_bound(filtered.begin(), filtered.end(), dummy, comp);
    int max_l = it - filtered.begin();
    int max_r = max_l - 1;

    for (int j = 0; j <= k; j++) {
      dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
      if (j + 1 <= k) {
        D use = max(dp1[i][j], dp2[i][j]);
        dp1[max_l][j + 1] = max(dp1[max_l][j + 1], use + filtered[i].second - filtered[i].first);
        if (max_r != i) {
          dp2[max_r][j + 1] = max(dp2[max_r][j + 1], use + filtered[max_r].first - filtered[i].first);
        }
      }
    }
  }

  D ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, dp1[m][i]);
  }

  cout << fixed << setprecision(10) << ans / PI << "\n";

  return 0;
}