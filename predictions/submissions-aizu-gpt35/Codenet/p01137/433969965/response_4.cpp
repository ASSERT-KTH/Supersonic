#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int e;
  while (cin >> e, e) {
    int ans = inf;
    int z_max = cbrt(e);
    for (int z = 0; z <= z_max; ++z) {
      int y_max = sqrt(e - z * z * z);
      for (int y = 0; y <= y_max; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}