#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

typedef long double D;
typedef std::pair<D, D> pdd;
typedef std::vector<D> vd;

const D EPS = 1e-8;
const D PI = std::acos(-1);

inline void modify(D& seta) {
  seta = std::fmod(seta + PI, 2 * PI) - PI;
}

inline bool in_upper(const D& seta) {
  return (EPS < seta && seta < PI - EPS);
}

struct comp {
  bool operator()(const pdd& a, const pdd& b) const {
    return std::abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector<pdd> v;
  v.reserve(n);

  for (int i = 0; i < n; i++) {
    D x, y, r;
    std::cin >> x >> y >> r;

    D d = std::sqrt(x * x + y * y);
    D s = std::atan2(y, x);
    D a = std::sqrt(d * d - r * r);
    D ds = std::acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds;
    D end = s + ds;
    modify(start);
    modify(end);
    pdd tmp = pdd(in_upper(start) ? start : 0, in_upper(end) ? end : PI);
    if (tmp.first < EPS && PI - EPS < tmp.second)
      continue;
    v.push_back(tmp);
  }

  std::sort(v.begin(), v.end(), comp());

  v.erase(std::remove_if(v.begin(), v.end(), [](const pdd& p) {
    return p.second - EPS < p.first;
  }), v.end());

  int m = v.size();

  std::vector<vd> dp1(m + 1, vd(k + 1, 0));
  std::vector<vd> dp2 = dp1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= k; j++) {
      dp1[i + 1][j] = std::max(dp1[i + 1][j], dp1[i][j]);
      if (j + 1 <= k) {
        D use = std::max(dp1[i][j], dp2[i][j]);
        dp1[v[i].second][j + 1] = std::max(dp1[v[i].second][j + 1], use + v[i].second - v[i].first);
        if (v[v[i].second].first != v[i].first) {
          dp2[v[v[i].second].first][j + 1] = std::max(dp2[v[v[i].second].first][j + 1], use + v[v[i].second].first - v[i].first);
        }
      }
    }
  }

  D ans = 0;

  for (int i = 0; i <= k; i++) {
    ans = std::max(ans, dp1[m][i]);
  }

  std::cout << std::fixed << std::setprecision(10) << ans / PI << "\n";

  return 0;
}