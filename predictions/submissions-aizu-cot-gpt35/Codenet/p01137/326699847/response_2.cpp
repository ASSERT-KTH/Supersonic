#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    int sqrt_e = sqrt(e);
    for (int z = sqrt_e; z >= 0; --z) {
      int val = z * z * z;
      int sqrt_e_minus_val = sqrt(e - val);
      for (int y = sqrt_e_minus_val; y >= 0; --y) {
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
  return 0;
}