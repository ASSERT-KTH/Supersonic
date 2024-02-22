#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      int max_y = sqrt(e - z * z * z);
      for (int y = 0; y <= max_y; ++y) {
        int yyzzz = y * y + z * z * z;
        int x = e - yyzzz;
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}