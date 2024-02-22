#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> v;
vector<int> m_cache;

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (auto& pair : v)
      sort(pair.second.begin(), pair.second.end());
    int D = 4 * R, ans = 0;
    m_cache.clear();
    for (int p = -D; p <= D; p++)
      m_cache.push_back(sqrt((D - p) * (D + p)));
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      int cache_index = 0;
      for (int p = -D; p <= D; p++, cache_index++) {
        if (v.count(y + p)) {
          int m = m_cache[cache_index];
          ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
                 lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
        }
      }
    }
    cout << ans << endl;
  }
}