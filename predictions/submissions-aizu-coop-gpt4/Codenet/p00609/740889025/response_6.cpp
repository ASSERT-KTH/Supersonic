#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

// Store all points in a single vector
vector<pii> v;

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    v.clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v.push_back(make_pair(y, x));
    }
    // Sort the vector once
    sort(v.begin(), v.end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= 10000)
          continue;
        // Calculate the value of m outside the loop
        int m = sqrt((D - p) * (D + p));
        // Use equal_range to perform the binary search once instead of twice
        auto range = equal_range(v.begin(), v.end(), make_pair(y + p, x - m), make_pair(y + p, x + m));
        ans += range.second - range.first;
      }
    }
    cout << ans << endl;
  }
}