#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> v[10001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i <= 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i <= 10000; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p > 10000) // Fix out of bounds error
          continue;
        int m = sqrt((D - abs(p)) * (D + abs(p))); // Avoid recomputing
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    cout << ans << endl;
  }
}