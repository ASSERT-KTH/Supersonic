#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

inline void modify(double& seta) {
  if (seta > M_PI)
    seta -= 2 * M_PI;
  if (seta < -M_PI)
    seta += 2 * M_PI;
}

inline bool in_upper(const double& seta) { 
  return (seta > 1e-8 && seta < M_PI - 1e-8);
}

struct pdd {
  double fs, sc;
};

bool comp(const pdd& a, const pdd& b) {
  return abs(a.fs - b.fs) < 1e-8 ? a.sc + 1e-8 < b.sc : a.fs < b.fs;
}

int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  
  vector<pdd> v;
  v.reserve(n);
  
  for (int i = 0; i < n; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    
    double d = sqrt(x * x + y * y);
    double s = atan2(y, x);
    double a = sqrt(d * d - r * r);
    double ds = acos((d * d + a * a - r * r) / (2 * d * a));
    double start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : M_PI);
    if (tmp.fs < 1e-8 && M_PI - 1e-8 < tmp.sc)
      continue;
    v.emplace_back(tmp);
  }
  
  vector<pdd>::iterator it = v.begin();
  while (it != v.end()) {
    it = remove_if(it + 1, v.end(), [&](const pdd& a) {
      return a.fs - 1e-8 < it->fs && it->sc < a.sc + 1e-8;
    });
  }
  v.erase(it, v.end());
  
  int m = v.size();
  
  vector<double> dp(m + 1, 0);
  
  for (int i = 0; i < m; i++) {
    dp[i + 1] = max(dp[i + 1], dp[i]);
    if (k > 0) {
      double use = max(dp[i], dp[i]);
      dp[i + 1] = max(dp[i + 1], use + v[i].sc - v[i].fs);
      if (i > 0) {
        dp[i + 1] = max(dp[i + 1], use + v[i].fs - v[i].fs);
      }
    }
  }
  
  double ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, dp[m]);
  }
  
  cout << fixed << setprecision(10) << ans / M_PI << "\n";
  
  return 0;
}