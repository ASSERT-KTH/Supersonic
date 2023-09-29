#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int y = sqrt(e - val);
      int val2 = val + y * y;
      if (val2 <= e)
        m = min(m, (e - val2) + y + z);
      if (y > 0) {
        y--;
        val2 = val + y * y;
        if (val2 <= e)
          m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << endl;
  }
  return 0;
}