#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int e;
  while (cin >> e && e) {
    int ans = e*3;
    for (int z = 0; z * z * z <= e; ++z) {
      int maxY = sqrt(e - z*z*z);
      for (int y = 0; y <= maxY; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}