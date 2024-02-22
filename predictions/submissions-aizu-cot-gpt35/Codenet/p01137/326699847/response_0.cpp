#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e)
        continue;
      int limit = sqrt(e - val);
      for (int y = limit; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        int temp = (e - val2) + y + z;
        if (temp < m)
          m = temp;
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}