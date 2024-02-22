#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

vector<pair<int, int>> v;
int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    v.reserve(aN);
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= -R; p++) {
        int m = (D - p) * (D + p);
        int yy = y + p;
        if (yy < 0 || yy >= 10000)
          continue;
        auto lower = lower_bound(v.begin(), v.end(), make_pair(x - sqrt(m), yy));
        auto upper = upper_bound(v.begin(), v.end(), make_pair(x + sqrt(m), yy));
        ans += upper - lower;
      }
      for (int p = R; p <= D; p++) {
        int m = (D - p) * (D + p);
        int yy = y + p;
        if (yy < 0 || yy >= 10000)
          continue;
        auto lower = lower_bound(v.begin(), v.end(), make_pair(x - sqrt(m), yy));
        auto upper = upper_bound(v.begin(), v.end(), make_pair(x + sqrt(m), yy));
        ans += upper - lower;
      }
    }
    cout << ans << endl;
  }
}