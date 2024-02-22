#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int remaining = e - val;
      for (int y = sqrt(remaining); y >= 0; --y) {
        int val2 = val + y * y;
        m = min(m, remaining - y * y + y + z);
      }
    }
    cout << m << "\n";
  }
  return 0;
}