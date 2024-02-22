#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
set<int> v[10000];
vector<int> usedIndices;
int preComputed[4*10000+1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int aN, bN, R;
  while (scanf("%d%d%d", &aN, &bN, &R), aN) {
    for (int i : usedIndices)
      v[i].clear();
    usedIndices.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].insert(x);
      usedIndices.push_back(y);
    }
    int D = 4 * R;
    for(int p=-D;p<=D;p++)
      preComputed[p+D] = sqrt((D - p) * (D + p));
    int ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = preComputed[p+D];
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}