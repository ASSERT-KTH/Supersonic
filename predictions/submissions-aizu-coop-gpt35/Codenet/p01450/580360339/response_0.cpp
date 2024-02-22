#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[10001][202]; // Optimized 2D array

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];

  // Initialize the dp array
  for (int j = 0; j <= W; j++) { // Fix loop initialization
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        dp[j][k] = 1;
      else
        dp[j][k] = 0;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;

    for (int j = 0; j <= W; j++) { // Fix loop initialization
      for (int k = 0; k <= N; k++) {
        dp[j][k] = 0; // Move computation outside the loop

        int nmwidx = k;
        if (k == N || w[k] > w[i])
          nmwidx = i;

        dp[j][k] += dp[cur][j][nmwidx];
        if (j + w[i] <= W)
          dp[j][k] += dp[cur][j + w[i]][k];
        dp[j][k] %= mod;
      }
    }
  }

  cout << dp[0][N] << endl; // Fix array indexing
  return 0;
}