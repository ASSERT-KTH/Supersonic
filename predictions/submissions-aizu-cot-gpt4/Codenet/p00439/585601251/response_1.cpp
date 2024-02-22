#include <algorithm>
#include <climits>
#include <iostream>
#include <deque>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    deque<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    long long sum = ac[k] - ac[0];
    res = max(res, sum);
    for (int i = k + 1; i <= n; ++i) {
      sum = sum - ac[i - k - 1] + ac[i];
      res = max(res, sum);
    }
    cout << res << endl;
  }
  return 0;
}