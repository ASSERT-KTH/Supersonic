#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    vector<vector<int>> dp(n+1, vector<int>(5, 0));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      int square = i * i;
      for (int k = 1; k <= 4; k++) {
        for (int j = square; j <= n; j++) {
          dp[j][k] += dp[j - square][k - 1];
        }
      }
    }
    cout << dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1] << "\n";
  }
}