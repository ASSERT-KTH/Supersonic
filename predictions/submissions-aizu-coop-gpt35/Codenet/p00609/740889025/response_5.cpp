#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> v;
int main() {
  int aN, bN, R;
  #pragma GCC optimize("O3")
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    v.resize(10000);
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y] = x;
    }
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        auto range = equal_range(v.begin() + y + p, v.begin() + y + p + 1, x - m, x + m);
        ans += distance(range.first, range.second);
      }
    }
    cout << ans << endl;
  }
}