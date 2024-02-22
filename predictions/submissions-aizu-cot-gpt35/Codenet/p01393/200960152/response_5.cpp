#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

inline void modify(double &seta) {
  const double PI = acos(-1);
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}

inline bool in_upper(const double &seta) { return (1e-8 < seta && seta < acos(-1) - 1e-8); }

inline bool comp(const pair<double, double> &a, const pair<double, double> &b) {
  const double EPS = 1e-8;
  return abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<double, double>> v;
  v.reserve(n);

  for (int i = 0; i < n; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    complex<double> c(x, y);
    double d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
    double ds = acos((d * d + a * a - r * r) / (2 * d * a));
    double start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pair<double, double> tmp = make_pair(in_upper(start) ? start : 0, in_upper(end) ? end : acos(-1));
    if (tmp.first < 1e-8 && acos(-1) - 1e-8 < tmp.second)
      continue;
    v.emplace_back(tmp);
  }

  sort(v.begin(), v.end(), comp);

  int m = v.size();
  vector<int> max_r(m), max_l(m);

  for (int i = 0; i < m; i++) {
    pair<double, double> dummy(v[i].second, 0);
    max_l[i] = upper_bound(v.begin(), v.end(), dummy, comp) - v.begin();
    max_r[i] = max_l[i] - 1;
  }

  vector<double> dp(m + 1, 0);

  for (int i = 0; i < m; i++) {
    for (int j = k; j >= 1; j--) {
      dp[j] = max(dp[j], dp[j-1]);
      if (j <= k) {
        double use = max(dp[j], dp[j-1]);
        dp[max_l[i]] = max(dp[max_l[i]], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp[max_r[i]] = max(dp[max_r[i]], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }

  double ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, dp[i]);
  }

  printf("%.10f\n", ans / acos(-1));

  return 0;
}