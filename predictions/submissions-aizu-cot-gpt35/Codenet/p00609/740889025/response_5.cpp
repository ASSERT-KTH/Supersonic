#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10000];

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y;
      v[y].push_back(x);
    }
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    cout << ans << endl;
  }
}