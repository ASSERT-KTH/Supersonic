#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    int maxZ = 100 * 100 * 100;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int maxy = sqrt(e - val);
      for (int y = maxy; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << endl;
  }
  return 0;
}