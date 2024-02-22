#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
set<int> v[10000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #pragma GCC optimize("Ofast")
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y;
      v[y].insert(x);
    }
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        ans += v[y + p].upper_bound(x + m) - v[y + p].lower_bound(x - m);
      }
    }
    cout << ans << endl;
  }
}