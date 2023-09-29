#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

typedef array<int, 2> pii;
vector<int> v[10000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
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
      sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        auto it = lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
        while (it != v[y + p].end() && *it <= x + m) {
          ans++;
          it++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}