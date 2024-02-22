#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int e;
  int m = 1000000;
  
  while (cin >> e, e) {
    int val = 0;
    int sqrt_e_val = sqrt(e);
    
    for (int z = sqrt_e_val; z >= 0; --z) {
      val = z * z * z;
      if (val > e)
        continue;
        
      int sqrt_e_val_minus_val = sqrt(e - val);
      for (int y = sqrt_e_val_minus_val; y >= 0; --y) {
        int val2 = val + y * y;
        if (val2 > e)
          continue;
        m = min(m, (e - val2) + y + z);
      }
    }
    
    cout << m << endl;
  }
  
  return EXIT_SUCCESS;
}