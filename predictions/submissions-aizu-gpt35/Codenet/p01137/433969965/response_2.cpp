#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = 1000000000;
    for (int z = 0; z * z * z <= e; ++z) {
      int ybound = min(static_cast<int>(sqrt(e - z * z * z)), 182);
      for (int y = 0; y <= ybound; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}