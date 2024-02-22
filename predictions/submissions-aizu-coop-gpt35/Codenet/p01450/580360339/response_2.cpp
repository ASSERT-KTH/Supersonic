#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int mod = 1000000007;
int N, W;
int w[201];
int dp[2][10001];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];

  for (int j = 0; j < 10001; j++) {
    for (int k = 0; k <= N; k++) {
      dp[N % 2][j] = (j <= W && (k == N || w[k] + j > W)) ? 1 : 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = i % 2;
    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k <= N; k++) {
        dp[nxt][j] = 0;
        int nmwidx = k;
        if (k == N || w[k] >= w[i])
          nmwidx = i;
        dp[nxt][j] += dp[cur][j][nmwidx];
        if (j + w[i] <= W)
          dp[nxt][j] += dp[cur][j + w[i]][k];
      }
    }
  }

  cout << dp[0][0] << endl;
  return 0;
}