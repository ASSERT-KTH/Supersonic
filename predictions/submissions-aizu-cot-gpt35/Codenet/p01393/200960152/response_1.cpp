#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

typedef pair<double, double> pdd;

const double EPS = 1e-8;
const double PI = acos(-1);

int n, k;
vector<pdd> v;
vector<int> max_l, max_r;

inline void modify(double& seta) {
  seta = fmod(seta, 2 * PI);
  if (seta < -PI) {
    seta += 2 * PI;
  }
}

inline bool in_upper(const double& seta) {
  return (seta > 0 && seta < PI);
}

inline bool comp(const pdd& a, const pdd& b) {
  return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  cin >> n >> k;
  
  rep(i, n) {
    double x, y, r;
    cin >> x >> y >> r;
    complex<double> c(x, y);
    double d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
    double ds = acos((d * d + a * a - r * r) / (2 * d * a));
    double start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.first < EPS && PI - EPS < tmp.second) {
      continue;
    }
    v.push_back(tmp);
  }
  
  sort(v.begin(), v.end(), comp);
  
  for (int i = 0; i < v.size(); i++) {
    pdd dummy(v[i].second, 0);
    max_l.push_back(upper_bound(v.begin(), v.end(), dummy, comp) - v.begin());
    max_r.push_back(max_l[i] - 1);
  }
  
  vector<double> dp1(k + 1, 0);
  
  for (int i = 0; i < v.size(); i++) {
    for (int j = k; j >= 0; j--) {
      dp1[j] = max(dp1[j], (j + 1 <= k ? dp1[j + 1] : 0));
      if (j + 1 <= k) {
        double use = dp1[j];
        dp1[max_l[i]] = max(dp1[max_l[i]], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp1[max_r[i]] = max(dp1[max_r[i]], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }
  
  double ans = *max_element(dp1.begin(), dp1.end());
  
  cout << ans / PI << "\n";
}