#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    vector<pii> v(aN);
    for (int i = 0; i < aN; i++) {
      cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());

    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      auto lower = lower_bound(v.begin(), v.end(), make_pair(y - D, -1));
      auto upper = upper_bound(v.begin(), v.end(), make_pair(y + D, INT_MAX));
      for (auto it = lower; it != upper; it++) {
        int dx = x - it->second;
        int dy = y - it->first;
        if (dx * dx + dy * dy <= D * D) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}