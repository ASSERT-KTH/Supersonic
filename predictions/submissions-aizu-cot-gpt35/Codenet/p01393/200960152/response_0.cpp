#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

typedef double D;
typedef pair<D, D> pdd;

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

  vector<pdd> v;
  v.reserve(n);

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
    v.emplace_back(tmp);
  }

  sort(v.begin(), v.end(), comp);

  int m = v.size();

  int i = 0, j = 0;
  while (j < m) {
    if (j != i && v[j].first - EPS < v[i].first && v[i].second < v[j].second + EPS) {
      swap(v[j], v[--m]);
    } else {
      j++;
    }
  }

  vector<int> max_r(m), max_l(m);
  for (int i = 0; i < m; i++) {
    pdd dummy(v[i].second, 0);
    auto it = upper_bound(v.begin(), v.end(), dummy, comp);
    max_l[i] = it - v.begin();
    max_r[i] = max_l[i] - 1;
  }

  vector<vector<D>> dp1(m + 1, vector<D>(k + 1, 0)), dp2(m + 1, vector<D>(k + 1, 0));
  dp1.resize(m + 1);
  dp2.resize(m + 1);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
      if (j + 1 <= k) {
        D use = max(dp1[i][j], dp2[i][j]);
        dp1[max_l[i]][j + 1] = max(dp1[max_l[i]][j + 1], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp2[max_r[i]][j + 1] = max(dp2[max_r[i]][j + 1], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }

  D ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, dp1[m][i]);
  }

  cout << fixed << setprecision(10) << ans / PI << "\n";
}