#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = 1e9;
    int maxZ = cbrt(e);
    for (int z = 0; z <= maxZ; ++z) {
      int maxXY = sqrt(e - z * z * z);
      for (int y = 0; y <= maxXY; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}