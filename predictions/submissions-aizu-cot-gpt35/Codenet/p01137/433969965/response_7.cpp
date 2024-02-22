#include <iostream>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = 1e9;
    for (int z = 0; z * z * z <= e; ++z) {
      int z_cubed = z * z * z;
      for (int y = 0; y * y <= e - z_cubed; ++y) {
        int x = e - (y * y + z_cubed);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}