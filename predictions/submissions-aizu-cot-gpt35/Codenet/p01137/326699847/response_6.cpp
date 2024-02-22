#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 0; z <= 100; ++z) {
      int val = z * z * z;
      if (val > e)
        continue;
      
      int sqrt_e_val = sqrt(e - val);
      for (int y = 0; y <= sqrt_e_val; ++y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        
        int new_m = (e - val2) + y + z;
        if (new_m < m)
          m = new_m;
      }
    }
    cout << m << endl;
  }
  return 0;
}