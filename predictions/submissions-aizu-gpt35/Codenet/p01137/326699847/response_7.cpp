#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int zCube = z * z * z;
      if (zCube > e) continue;
      int maxJ = sqrt(e - zCube);
      for (int y = maxJ; y >= 0; --y) {
        int val = zCube + y * y;
        if (val > e) continue;
        m = min(m, (e - val) + y + z);
      }
    }
    cout << m << endl;
  }
  return 0;
}