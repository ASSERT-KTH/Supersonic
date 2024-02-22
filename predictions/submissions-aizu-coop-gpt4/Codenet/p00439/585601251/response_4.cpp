#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  while (cin >> n >> k, n) {
    long long ac[n + 1];
    ac[0] = 0;
    long long res = -LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
      if (i >= k) {
        res = max(res, ac[i] - ac[i - k]);
      }
    }
    cout << res << endl;
  }
  return 0;
}