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
    // Initialize window_sum with the sum of the first k integers
    long long window_sum = ac[k] - ac[0];
    res = max(res, window_sum);
    for (int i = k + 1; i <= n; ++i) {
      // Update window_sum by subtracting the first integer of the previous window
      // and adding the next integer in the sequence
      window_sum = window_sum - ac[i - k - 1] + ac[i];
      res = max(res, window_sum);
    }
    cout << res << endl;
  }
  return 0;
}