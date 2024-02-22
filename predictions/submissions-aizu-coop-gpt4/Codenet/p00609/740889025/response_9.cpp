#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
map<int, vector<int>> v;

int main() {
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R), aN) {
    v.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (auto& p : v)
      sort(p.second.begin(), p.second.end());
    int D = 4 * R * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (v.count(y + p) == 0)
          continue;
        int m = (D - p * p);
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}