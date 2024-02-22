#include <iostream>
using namespace std;

const int mod = 1000000007;

int N, W;
int w[201];
int dp[202][10001][202];

int main() {
  cin >> N >> W;
  
  for (int i = 0; i < N; i++)
    cin >> w[i];
  
  for (int j = 0; j <= W; j++) {
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        dp[k][j][k] = 1;
      else
        dp[k][j][k] = 0;
    }
  }
  
  for (int i = N; i >= 1; i--) {
    int cur = i % 2;
    int nxt = (i + 1) % 2;
    
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        dp[k][j][nxt] = 0;
        int nmwidx = k;
        if (k == N || w[k] > w[i - 1])
          nmwidx = i - 1;
        dp[k][j][nxt] += dp[nmwidx][j][cur];
        if (j + w[i - 1] <= W)
          dp[k][j][nxt] += dp[k][j + w[i - 1]][cur];
        dp[k][j][nxt] %= mod;
      }
    }
  }
  
  cout << dp[N][0][0] << endl;
  return 0;
}