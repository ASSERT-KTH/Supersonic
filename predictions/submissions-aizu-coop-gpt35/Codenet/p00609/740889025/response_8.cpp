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
    
    for (auto it = v.begin(); it != v.end(); ++it) {
      stable_sort(it->second.begin(), it->second.end());
    }
    
    int D = 4 * R, ans = 0;
    
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        
        int sqrtDp = sqrt(D * D - p * p);
        int m = sqrtDp;
        
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    
    cout << ans << endl;
  }
}