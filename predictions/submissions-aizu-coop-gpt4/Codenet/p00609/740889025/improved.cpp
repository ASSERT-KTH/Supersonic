#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main() {
  int x, y;
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    vector<int> v[10000];
    for (int i = 0; i < aN; i++) {
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt(D * D - p * p);
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    printf("%d\n", ans);
  }
}
