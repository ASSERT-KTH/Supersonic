#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    long long min_val = 0;
    for (int i = k; i <= n; ++i) {
      min_val = min(min_val, ac[i - k]);
      res = max(res, ac[i] - min_val);
    }
    cout << res << '\n';
  }
  return 0;
}