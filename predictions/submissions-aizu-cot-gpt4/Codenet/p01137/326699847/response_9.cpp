#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int max_y = sqrt(e - val);
      for (int y = max_y; y >= 0; --y) {
        auto val2 = val + y * y;
        if (val2 > e)
          continue;
        m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}