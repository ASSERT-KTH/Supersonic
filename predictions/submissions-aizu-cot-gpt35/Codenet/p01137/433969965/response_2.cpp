#include <iostream>
#include <cmath>

using namespace std;

int main() {
  unsigned int e;
  while (cin >> e, e) {
    int ans = e; // Initialize ans with the maximum possible value of x + y + z
    for (int z = cbrt(e); z >= 0; --z) {
      unsigned int max_y = sqrt(e - z * z * z);
      for (int y = max_y; y >= 0; --y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
        if (x == 0) {
          break; // Break out of the inner loop if x is 0
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}