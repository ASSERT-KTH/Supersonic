#include <vector>
#include <complex>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>

typedef double D;
typedef std::pair<D, D> pdd;
typedef std::vector<D> vd;
const D EPS = 1e-8;
const D PI = acos(-1);
int n, k;
pdd p[2000];
std::vector<pdd> v;

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
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> n >> k;
  v.reserve(n);
  for(int i = 0; i < n; i++) {
    D x, y, r;
    std::cin >> x >> y >> r;
    std::complex<D> c(x, y);
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
  std::sort(v.begin(), v.end(), comp);
  for(int i = 0; i < v.size(); i++) for(int j = 0; j < v.size(); j++) {
    if (i == j)
      continue;
    if (v[j].first - EPS < v[i].first && v[i].second < v[j].second + EPS) {
      v.erase(v.begin() + i);
      i--;
      break;
    }
  }
  int m = v.size();
  std::vector<vd> dp1(m + 1, vd(k + 1, 0)), dp2 = dp1;
  for(int i = 0; i < m; i++) for(int j = 0; j < k + 1; j++) {
    dp1[i + 1][j] = std::max(dp1[i + 1][j], dp1[i][j]);
    if (j + 1 <= k) {
      D use = std::max(dp1[i][j], dp2[i][j]);
      dp1[i + 1][j + 1] = std::max(dp1[i + 1][j + 1], use + v[i].second - v[i].first);
      if (i != i) {
        dp2[i][j + 1] =
            std::max(dp2[i][j + 1], use + v[i].first - v[i].first);
      }
    }
  }
  D ans = 0;
  for(int i = 0; i < k + 1; i++) ans = std::max(ans, dp1[m][i]);
  std::cout << std::fixed << std::setprecision(10) << ans / PI << "\n";
}