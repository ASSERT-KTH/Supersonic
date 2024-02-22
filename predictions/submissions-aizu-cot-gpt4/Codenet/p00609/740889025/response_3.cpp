#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> v[10000];
double sqrt_values[20001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int aN, bN, R;
  for (int i = 0; i <= 20000; ++i) {
    sqrt_values[i] = sqrt((10000 - i) * (10000 + i));
  }
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
    int start = max(0, -D), end = min(9999, bN + D);
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      for (int p = start; p <= end; p++) {
        vector<int> &vp = v[y + p];
        int m = sqrt_values[D + p];
        ans += upper_bound(vp.begin(), vp.end(), x + m) -
               lower_bound(vp.begin(), vp.end(), x - m);
      }
    }
    cout << ans << endl;
  }
}