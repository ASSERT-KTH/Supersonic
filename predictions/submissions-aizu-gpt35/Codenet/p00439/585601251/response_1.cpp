#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  while (cin >> n >> k, n) {
    vector<int> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    int res = -INT_MAX;
    for (int i = k; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k]);
    }
    cout << res << endl;
  }
  return 0;
}