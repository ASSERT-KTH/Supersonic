#include <iostream>
#include <vector>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = INT_MAX;
    int maxZ = cbrt(e);
    for (int z = 0; z <= maxZ; ++z) {
      int maxY = sqrt(e - z * z * z);
      for (int y = 0; y <= maxY; ++y) {
        int x = e - (y * y + z * z * z);
        if (x >= 0) {
          ans = min(ans, x + y + z);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}