#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#define ALL(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    int val, val2;
    for (int z = 100; z >= 0; --z) {
      val = z * z * z;
      if (val > e)
        break;  // Optimization 1: Break the loop when 'val' is more than 'e'
      for (int y = sqrt(e - val); y >= 0; --y) {
        val2 = val + y * y;
        if (val2 > e)
          break;  // Optimization 2: Break the loop when 'val2' is more than 'e'
        m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << '\n';
  }
  return 0;
}