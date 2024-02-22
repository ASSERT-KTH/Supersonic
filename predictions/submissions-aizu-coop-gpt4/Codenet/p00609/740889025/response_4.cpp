#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[10000];
int m[80001]; // to store pre-calculated values of m
int main() {
  int aN, bN, R;
  while (scanf("%d %d %d", &aN, &bN, &R), aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++) {
      if (!v[i].empty()) // avoid sorting empty vectors
        sort(v[i].begin(), v[i].end());
    }
    int D = 4 * R, ans = 0;
    for (int p = -D; p <= D; p++) {
      m[p + D] = sqrt((D - p) * (D + p)); // pre-calculate values of m
    }
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m[p + D]) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m[p + D]);
      }
    }
    printf("%d\n", ans);
  }
}