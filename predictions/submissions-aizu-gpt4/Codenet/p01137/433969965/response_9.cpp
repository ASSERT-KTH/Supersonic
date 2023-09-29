#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int e;
  while (cin >> e, e) {
    int ans = e;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = z; y * y + z * z * z <= e; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}