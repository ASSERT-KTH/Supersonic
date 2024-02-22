#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main() {
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    // Find the maximum value of y
    int maxY = 0;
    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      maxY = max(maxY, y);
    }

    // Dynamically allocate memory for v based on maxY
    vector<vector<int>> v(maxY + 1);

    for (int i = 0; i < aN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      v[y].push_back(x);
    }

    // Sort only the vectors that have elements
    for (int i = 0; i <= maxY; i++) {
      if (!v[i].empty()) {
        sort(v[i].begin(), v[i].end());
      }
    }

    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p > maxY) {
          continue;
        }
        int m = sqrt((D - p) * (D + p));
        ans += binarySearch(v[y + p], x - m, x + m);
      }
    }
    cout << ans << endl;
  }
}

// Custom binary search function
int binarySearch(const vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int count = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] <= target) {
      count = mid + 1;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return count;
}