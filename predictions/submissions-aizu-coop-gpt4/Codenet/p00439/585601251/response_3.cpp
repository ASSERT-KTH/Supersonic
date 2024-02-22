#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k, n) {
    long long ac[n + 1] = {0};
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    for (int i = 1; i < k; ++i) {
      res = max(res, ac[i]);
    }
    for (int i = k; i <= n; ++i) {
      long long temp = ac[i] - ac[i - k];
      res = max(res, temp);
    }
    cout << res << endl;
  }
  return 0;
}