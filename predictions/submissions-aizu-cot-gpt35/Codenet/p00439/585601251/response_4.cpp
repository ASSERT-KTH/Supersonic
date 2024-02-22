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
    long long prevSum = 0;
    long long curSum = 0;
    long long res = -LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
      cin >> curSum;
      curSum += prevSum;
      if (i > k) {
        prevSum -= curSum - ac[i - k];
      }
      res = max(res, curSum);
    }
    cout << res << endl;
  }
  return 0;
}