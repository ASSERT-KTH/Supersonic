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
    }
    long long res = -LLONG_MAX;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += ac[i];
      if (i >= k) {
        res = max(res, sum);
        sum -= ac[i - k + 1];
      }
    }
    cout << res << endl;
  }
  return 0;
}