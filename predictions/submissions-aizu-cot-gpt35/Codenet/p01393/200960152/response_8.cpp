#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using D = double;
using pdd = pair<D, D>;
using vd = vector<D>;

const D EPS = 1e-8;
const D PI = acos(-1);

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
    D d = hypot(x, y);
    D s = atan2(y, x);
    D a = sqrt(d * d - r * r);
    D ds = acos((d * d + a * a - r * r) / (2 * d * a));
    D start = s - ds;
    D end = s + ds;
    pdd tmp = make_pair(start, end);
    if (tmp.first < EPS && PI - EPS < tmp.second) continue;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  v.erase(remove_if(v.begin(), v.end(), [](const pdd& a, const pdd& b) {
    return a.second - EPS < b.first && b.second + EPS < a.second;
  }), v.end());

  int m = v.size();
  vector<int> max_l(m), max_r(m);

  for (int i = 0, j = 0; i < m; i++) {
    while (j < m && v[j].first < v[i].second + EPS) j++;
    max_l[i] = j;
    max_r[i] = j - 1;
  }

  vector<vd> dp1(m + 1, vd(k + 1, 0));
  vector<vd> dp2(dp1);

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

  D ans = accumulate(dp1[m].begin(), dp1[m].end(), 0.0, [](D a, D b) { return max(a, b); });
  cout << fixed << setprecision(10) << ans / PI << "\n";

  return 0;
}