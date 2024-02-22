#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int main() {
  int e;
  while (cin >> e, e) {
    int ans = INT_MAX;
    for (int z = 0, z3 = 0; z3 <= e; ++z, z3 = z*z*z) {
      for (int y = 0, y2 = 0; y2 + z3 <= e; ++y, y2 = y*y) {
        int x = e - (y2 + z3);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}