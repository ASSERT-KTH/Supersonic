#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y + z * z * z <= e; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}