#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = 1e9;
    int max_z = cbrt(e);
    for (int z = 0; z <= max_z; ++z) {
      int max_y = sqrt(e - z * z * z);
      for (int y = 0; y <= max_y; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}