#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      for (int y = 0; y * y + z * z * z <= e; ++y) {
        int x = e - (y * y + z * z * z);
        ans = min(ans, x + y + z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}