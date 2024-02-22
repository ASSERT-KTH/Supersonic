#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

map<int, vector<int>> v;

int main() {
  int aN, bN, R;
  
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }
    
    int D = 4 * R;
    int ans = 0;
    
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      
      for (int p = -D; p <= D; p += 4) {
        if (y + p < 0 || y + p >= 10000)
          continue;
          
        int m = (int)sqrt((double)((D - p) * (D + p)));
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    
    cout << ans << endl;
  }
}