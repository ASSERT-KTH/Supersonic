#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[10000];
bool used[10000] = {false};
int main() {
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R) != EOF, aN) {
    int usedCount = 0;
    int usedIndices[10000];
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (!used[y]) {
        used[y] = true;
        usedIndices[usedCount++] = y;
      }
      v[y].push_back(x);
    }
    for (int i = 0; i < usedCount; i++)
      sort(v[usedIndices[i]].begin(), v[usedIndices[i]].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < usedCount; i++) {
      v[usedIndices[i]].clear();
      used[usedIndices[i]] = false;
    }
  }
}