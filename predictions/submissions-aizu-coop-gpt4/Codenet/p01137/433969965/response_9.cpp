#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y + z * z * z <= e; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
        // Break the loop as soon as a solution is found
        if (x + y + z == e) break;
      }
      // Break the outer loop if a solution has been found
      if (ans < inf) break;
    }
    cout << ans << endl;
  }
  return 0;
}