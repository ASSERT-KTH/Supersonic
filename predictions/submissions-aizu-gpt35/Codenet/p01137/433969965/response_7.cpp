#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0;; ++y) {
        int p = y * y + z * z * z;
        if (p > e) break;
        int x = e - p;
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}