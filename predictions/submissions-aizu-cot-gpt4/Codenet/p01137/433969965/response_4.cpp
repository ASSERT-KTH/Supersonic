#include <bits/stdc++.h>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = INT_MAX;
    int y = 0;
    for (int z = 0; ; ++z) {
      int z_cubed = z * z * z;
      if (z_cubed > e) break;
      for (; ; ++y) {
        int y_squared = y * y;
        if (y_squared + z_cubed > e) break;
        int x = e - (y_squared + z_cubed);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}