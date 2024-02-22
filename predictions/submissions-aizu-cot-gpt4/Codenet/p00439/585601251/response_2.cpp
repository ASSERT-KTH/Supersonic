#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> ac[i];
      if (i < k) {
        sum += ac[i];
      }
    }
    long long res = sum;
    for (int i = k; i < n; ++i) {
      sum = sum - ac[i - k] + ac[i];
      res = max(res, sum);
    }
    cout << res << endl;
  }
  return 0;
}