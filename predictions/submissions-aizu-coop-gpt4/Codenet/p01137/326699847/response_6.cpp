#include "bits/stdc++.h"
#define ALL(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;  // Moved outside the inner loop
      if (val > e) continue;
      int y_lower_bound = sqrt(e - val);  // Compute lower bound for y
      for (int y = y_lower_bound; y >= 0; --y) {
        int val2 = val + y * y;
        // Removed the if (val2 > e) check
        m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}