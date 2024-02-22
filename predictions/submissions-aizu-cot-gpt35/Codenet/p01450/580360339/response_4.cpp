#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001][201];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (size_t j = 0; j < W + 1; j++) {
    for (size_t k = 0; k < N; k++) {
      if (j <= W && (k == N - 1 || w[k] + j > W))
        dp[N % 2][j][k] = 1;
      else
        dp[N % 2][j][k] = 0;
    }
  }
  for (int i = N - 2; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (size_t j = 0; j < W + 1; j++) {
      for (size_t k = 0; k < N; k++) {
        dp[nxt][j][k] = 0;
        int nmwidx = k;
        if (k == N - 1 || w[k] > w[i])
          nmwidx = i;
        dp[nxt][j][k] += dp[cur][j][nmwidx];
        if (j + w[i] <= W)
          dp[nxt][j][k] += dp[cur][j + w[i]][k];
        dp[nxt][j][k] %= mod;
      }
    }
  }
  cout << dp[0][0][N - 1] << endl;
  return 0;
}