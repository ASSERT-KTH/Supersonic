#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
vector<int> v[10000];
int main() {
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R), aN) {
    for (auto& vi : v)
      vi.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (auto& vi : v)
      if (!vi.empty())
        sort(vi.begin(), vi.end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = max(0, -D); p <= min(9999, D); p++) {
        int m = sqrt(D * D - p * p);
        if (!v[y + p].empty())
          ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
                 lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}