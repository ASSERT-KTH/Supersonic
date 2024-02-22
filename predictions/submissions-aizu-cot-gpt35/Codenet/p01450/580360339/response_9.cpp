#include <iostream>
using namespace std;
typedef long long ll;

const unsigned int mod = 1000000007;

unsigned int N, W;
int w[201];
ll dp[2][10001][202];

int main() {
  cin >> N >> W;
  
  for (unsigned int i = 0; i < N; i++)
    cin >> w[i];

  for (int j = 0; j < 10001; j++) {
    for (int k = 0; k <= N; k++) {
      dp[N % 2][j][k] = (j <= W && (k == N || w[k] + j > W)) ? 1 : 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;

    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k <= N; k++) {
        dp[i % 2][j][k] = 0;

        int nmwidx = i;
        dp[i % 2][j][k] += dp[cur][j][nmwidx];

        if (j + w[i] <= W)
          dp[i % 2][j][k] += dp[cur][j + w[i]][k];

        dp[i % 2][j][k] %= mod;
      }
    }
  }

  cout << dp[0][0][N] << endl;
  return 0;
}