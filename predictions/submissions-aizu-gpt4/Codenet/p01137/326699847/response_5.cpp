#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    int limit = cbrt(e);
    for (int z = limit; z >= 0; --z) {
      int val = z * z * z;
      int y_limit = sqrt(e - val);
      for (int y = y_limit; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 <= e) {
          m = min(m, (e - val2) + y + z);
        } else {
          break;
        }
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}