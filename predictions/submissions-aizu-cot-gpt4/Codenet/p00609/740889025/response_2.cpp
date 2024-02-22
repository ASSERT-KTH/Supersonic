#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[10000];
int main() {
  ios::sync_with_stdio(false); // to speed up I/O operations
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear(); // clear the vector after using its elements
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y; // use std::cin instead of scanf
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      if (!v[i].empty()) // avoid sorting empty vectors
        sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y; // use std::cin instead of scanf
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        int m = sqrt((D - p) * (D + p));
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m);
      }
    }
    cout << ans << endl;
  }
}