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
    vector<int> ac(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    int res = INT_MIN;
    for (int i = k; i <= n; ++i) {
      if (ac[i] - ac[i - k] > res) {
        res = ac[i] - ac[i - k];
      }
    }
    cout << res << endl;
  }
  return 0;
}