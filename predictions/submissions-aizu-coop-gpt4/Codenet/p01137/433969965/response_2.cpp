#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = e + 2;
    for (int z = cbrt(e); z >= 0; --z) {
      for (int y = sqrt(e - z * z * z); y >= 0; --y) {
        int x = e - (y * y + z * z * z);
        if (x + y + z < ans) {
          ans = x + y + z;
          // break the inner loop because any other y would result in a larger sum
          break;
        }
      }
      // break the outer loop because any other z would result in a larger sum
      if (ans < e + 2) break;
    }
    cout << ans << endl;
  }
  return 0;
}