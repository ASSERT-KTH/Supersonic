#include <iostream>
#include <cmath>
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100, val = z * z * z; z >= 0; --z, val -= 3 * z * z + 3 * z + 1) {
      if (val > e)
        continue;
      for (int y = sqrt(e - val), val2 = val + y * y; y >= 0; --y, val2 -= 2 * y + 1) {
        if (val2 > e)
          continue;
        m = min(m, e - val2 + y + z);
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}