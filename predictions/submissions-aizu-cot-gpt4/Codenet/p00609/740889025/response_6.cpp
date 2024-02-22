#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> v[10000];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y;
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      for (int p = -D; p <= D; p++) {
        int yp = max(0, min(y + p, 9999));
        int m = sqrt((D - p) * (D + p));
        ans += upper_bound(v[yp].begin(), v[yp].end(), x + m) -
               lower_bound(v[yp].begin(), v[yp].end(), x - m);
      }
    }
    cout << ans << '\n';
  }
}