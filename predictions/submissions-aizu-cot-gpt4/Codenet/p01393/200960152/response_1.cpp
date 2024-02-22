#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using D = double;
using P = std::pair<D, D>;

const D EPS = 1e-8;
const D PI = acos(-1);

P p[2000];
std::vector<P> v;
int max_r[2000], max_l[2000];

inline void modify(D &seta) {
  if (seta > PI)
    seta -= 2 * PI;
  if (seta < -PI)
    seta += 2 * PI;
}

inline bool in_upper(const D &seta) { return (EPS < seta && seta < PI - EPS); }

inline bool comp(const P &a, const P &b) {
  return abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    D x, y, r;
    std::cin >> x >> y >> r;
    std::complex<D> c(x, y);
    D d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds, end = s + ds;
    modify(start);
    modify(end);
    P tmp = P(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.first < EPS && PI - EPS < tmp.second)
      continue;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end(), comp);

  for(int i = 0; i < v.size(); i++) {
    while(i + 1 < v.size() && v[i + 1].first - EPS < v[i].first && v[i].second < v[i + 1].second + EPS) {
      v.erase(v.begin() + i);
    }
  }

  int m = v.size();
  for (int i = 0; i < m; i++) {
    P dummy(v[i].second, 0);
    max_l[i] = upper_bound(v.begin(), v.end(), dummy, comp) - v.begin();
    max_r[i] = max_l[i] - 1;
  }

  D dp1[2001][2001] = {0}, dp2[2001][2001] = {0};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      dp1[i + 1][j] = std::max(dp1[i + 1][j], dp1[i][j]);
      if (j + 1 <= k) {
        D use = std::max(dp1[i][j], dp2[i][j]);
        dp1[max_l[i]][j + 1] = std::max(dp1[max_l[i]][j + 1], use + v[i].second - v[i].first);
        if (max_r[i] != i) {
          dp2[max_r[i]][j + 1] =
              std::max(dp2[max_r[i]][j + 1], use + v[max_r[i]].first - v[i].first);
        }
      }
    }
  }

  D ans = 0;
  for (int i = 0; i <= k; i++) ans = std::max(ans, dp1[m][i]);
  std::cout << std::fixed << std::setprecision(10) << ans / PI << "\n";
}