#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1000000000;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      int sum = z * z * z;
      for (int y = 0; sum <= e; ++y) {
        int x = e - sum;
        ans = min(ans, x + y + z);
        sum += y * y + 3 * z * z;
      }
    }
    cout << ans << endl;
  }
  return 0;
}