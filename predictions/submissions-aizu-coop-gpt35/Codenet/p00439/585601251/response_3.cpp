#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    long long ac[n + 1] = {0};
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
    }
    for (int i = 1; i <= n; ++i) {
      ac[i] += ac[i - 1];
    }
    long long res = ac[k];
    for (int i = k; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k - 1]);
    }
    cout << res << endl;
  }
  return 0;
}