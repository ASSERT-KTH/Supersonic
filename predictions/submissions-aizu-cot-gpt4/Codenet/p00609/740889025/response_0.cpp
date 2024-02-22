#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
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
      v[y].insert(lower_bound(v[y].begin(), v[y].end(), x), x);
    }
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        vector<int>& vp = v[y + p];
        ans += upper_bound(vp.begin(), vp.end(), x + m) -
               lower_bound(vp.begin(), vp.end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}