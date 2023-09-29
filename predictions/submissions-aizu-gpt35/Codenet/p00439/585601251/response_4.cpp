#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n + 1, 0);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      sum += ac[i];
      if (i >= k) {
        sum -= ac[i - k];
      }
      if (i >= k - 1) {
        res = max(res, sum);
      }
    }
    cout << res << endl;
  }
  return 0;
}