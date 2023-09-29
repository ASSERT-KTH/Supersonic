#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
constexpr int MAX_SIZE = 10000;
vector<int> v[MAX_SIZE];
int main() {
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R), aN) {
    for (int i = 0; i < MAX_SIZE; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < MAX_SIZE; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = max(0, -D); p <= min(D, MAX_SIZE - y - 1); p++) {
        int m = (D - p) * (D + p);
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}