#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = 1000000000;
    for (int y = 0; y * y <= e; ++y) {
      int y2 = y * y;
      int z = cbrt(e - y2);
      int z3 = z * z * z;
      int x = e - (y2 + z3);
      ans = min(ans, x + y + z);
    }
    cout << ans << endl;
  }
  return 0;
}