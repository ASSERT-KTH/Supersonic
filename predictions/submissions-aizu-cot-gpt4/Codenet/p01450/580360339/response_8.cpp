#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001][2]; // Reduce the size of the last dimension of the DP table to 2
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j < 10001; j++) {
    for (int k = 0; k < 2; k++) {
      if (j <= W && (k == 1 || w[k] + j > W))
        dp[N % 2][j][k] = 1;
      else
        dp[N % 2][j][k] = 0;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k < 2; k++) { // Reduce the range of 'k'
        dp[nxt][j][k] = 0;
        int nmwidx = k;
        if (k == 1 || w[k] > w[i])
          nmwidx = i % 2; // Use 'i % 2' instead of 'i'
        dp[nxt][j][k] += dp[cur][j][nmwidx];
        if (j + w[i] <= W)
          dp[nxt][j][k] += dp[cur][j + w[i]][k];
        if (dp[nxt][j][k] >= mod) // Perform the modulo operation only when necessary
          dp[nxt][j][k] %= mod;
      }
    }
  }
  cout << dp[0][0][1] << endl; // Use '1' instead of 'N'
  return 0;
}