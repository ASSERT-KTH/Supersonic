#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> v[10000];
int main() {
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R), aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      int p = max(0, y - 2 * R), q = min(9999, y + 2 * R);
      for (; p <= q; p++) {
        int m = static_cast<int>(sqrt(D - (y - p) * (y - p)));
        ans += upper_bound(v[p].begin(), v[p].end(), x + m) -
               lower_bound(v[p].begin(), v[p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}