#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAX_N = 200;
const int MAX_W = 10000;
int N, W;
int w[MAX_N + 1];
ll dp[2][MAX_W + 1][MAX_N + 1];

int main() {
  cin >> N >> W;
  for (int i = 1; i <= N; i++)
    cin >> w[i];
  sort(w + 1, w + N + 1);
  dp[0][0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
        if (j >= w[i])
          dp[i % 2][j][k] += dp[(i - 1) % 2][j - w[i]][k - 1];
        dp[i % 2][j][k] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    ans += dp[N % 2][W][i];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}