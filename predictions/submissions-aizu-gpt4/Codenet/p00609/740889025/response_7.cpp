#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<int> v[10000];

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      if (!v[i].empty())
        sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = max(0, y - D); p <= min(9999, y + D); p++) {
        int m = sqrt((D - p + y) * (D + p - y));
        ans += upper_bound(v[p].begin(), v[p].end(), x + m) -
               lower_bound(v[p].begin(), v[p].end(), x - m);
      }
    }
    cout << ans << endl;
  }
}