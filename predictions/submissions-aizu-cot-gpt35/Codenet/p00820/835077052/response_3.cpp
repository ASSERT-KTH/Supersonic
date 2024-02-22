#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
static const double EPS = 1e-8;
int dp[5];
int main() {
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= min(4, n - i * i + 1); k++) {
        for (int j = n - i * i * (4 - k); j >= i * i; j--) {
          dp[k] += dp[j - i * i];
        }
      }
    }
    cout << dp[4] + dp[3] + dp[2] + dp[1] << endl;
  }
}