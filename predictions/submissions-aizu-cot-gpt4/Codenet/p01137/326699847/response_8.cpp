#include "bits/stdc++.h"
#define ALL(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;
int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    int precomp_z[101];
    for (int z = 100; z >= 0; --z)
      precomp_z[z] = z * z * z;
    for (int z = 100; z >= 0; --z) {
      if (precomp_z[z] > e)
        continue;
      for (int val2 = e - precomp_z[z]; val2 >= 0; val2--) {
        int y = sqrt(val2);
        if (val2 + precomp_z[z] > e)
          break;
        m = min(m, (e - (val2 + precomp_z[z])) + y + z);
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}