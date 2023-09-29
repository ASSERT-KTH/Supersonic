#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int e;
  while (cin >> e, e) {
    int ans = INT_MAX;
    for (int z = cbrt(e); z >= 0; --z) {
      for (int y = sqrt(e - z * z * z); y >= 0; --y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}