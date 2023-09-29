#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = LLONG_MIN;
    for (int i = k; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k]);
    }
    cout << res << endl;
  }
  return 0;
}