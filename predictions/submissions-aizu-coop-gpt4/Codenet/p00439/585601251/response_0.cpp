#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    long long min_ac = 0;  // Initialize minimum prefix sum
    for (int i = 1; i <= n; ++i) {
      if (i > k) {
        min_ac = min(min_ac, ac[i - k - 1]);  // Update minimum prefix sum
      }
      res = max(res, ac[i] - min_ac);  // Subtract minimum prefix sum from current prefix sum
    }
    cout << res << endl;
  }
  return 0;
}