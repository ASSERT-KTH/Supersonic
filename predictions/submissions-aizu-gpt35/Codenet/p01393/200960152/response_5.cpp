#include <bits/stdc++.h>
using namespace std;

typedef double D;
typedef pair<D, D> pdd;

const D EPS = 1e-8;
const D PI = acos(-1);

int n, k;

inline bool in_upper(const D &seta) { return (EPS < seta && seta < PI - EPS); }
inline bool comp(const pdd &a, const pdd &b) {
  return abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n >> k;
  vector<pdd> v;
  for(int i = 0; i < n; ++i) {
    D x, y, r;
    cin >> x >> y >> r;
    D d = sqrt(x * x + y * y), s = atan2(y, x), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    while(start > PI) start -= 2 * PI;
    while(start < -PI) start += 2 * PI;
    while(end > PI) end -= 2 * PI;
    while(end < -PI) end += 2 * PI;
    pdd tmp = pdd(in_upper(start) ? start : -PI, in_upper(end) ? end : PI);
    if (tmp.first < EPS - PI && PI - EPS < tmp.second)
      continue;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end(), comp);
  int m = v.size();
  int max_l[m], max_r[m];
  for(int i = 0; i < m; ++i) {
    pdd dummy(v[i].second, 0);
    max_l[i] = upper_bound(v.begin(), v.end(), dummy, comp) - v.begin();
    max_r[i] = max_l[i] - 1;
  }
  vector<D> dp1(m + 1, 0), dp2 = dp1;
  for(int j = 0; j < k; ++j) {
    for(int i = 0; i < m; ++i) {
      dp1[i + 1] = max(dp1[i + 1], dp1[i]);
      if (j + 1 <= k) {
        D use = max(dp1[i], dp2[i]);
        dp1[max_l[i]] = max(dp1[max_l[i]], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp2[max_r[i]] = max(dp2[max_r[i]], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }
  cout << fixed << setprecision(10) << max(dp1[m], dp2[m-1]) / PI << "\n";
}
