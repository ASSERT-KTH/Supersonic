#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 10005;
vector<int> v[MAXN];
int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < MAXN; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < MAXN; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      int l = max(0, y - D), r = min(MAXN - 1, y + D);
      for (int p = l; p <= r; p++) {
        int m = sqrt((D + p - y) * (D - p + y));
        int lx = lower_bound(v[p].begin(), v[p].end(), x - m) - v[p].begin();
        int rx = upper_bound(v[p].begin(), v[p].end(), x + m) - v[p].begin();
        ans += rx - lx;
      }
    }
    cout << ans << endl;
  }
}