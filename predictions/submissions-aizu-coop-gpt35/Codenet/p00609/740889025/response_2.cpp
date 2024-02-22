#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
map<int, vector<int>> v;

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    for (auto& entry : v) {
      sort(entry.second.begin(), entry.second.end());
    }
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = (D - p) * (D + p);
        int left = 0, right = v[y + p].size();
        int low = 0, high = right;
        while (low < high) {
          int mid = (low + high) / 2;
          if (v[y + p][mid] >= x - m) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        left = low;
        low = 0, high = right;
        while (low < high) {
          int mid = (low + high) / 2;
          if (v[y + p][mid] > x + m) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        right = low;
        ans += right - left;
      }
    }
    cout << ans << endl;
  }
}