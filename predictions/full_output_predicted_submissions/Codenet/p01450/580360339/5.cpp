#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001][202];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j < 10001; j++) {
    for (int k = 0; k <= N; k++) {
      if (j <= W && (k == N || w[k] + j > W))
        dp[N % 2][j][k] = 1;
      else
        dp[N % 2][j][k] = 0;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k <= N; k++) {
        dp[nxt][j][k] = 0;
        int nmwidx = k;
        if (k == N || w[k] > w[i])
          nmwidx = i;
        dp[nxt][j][k] += dp[cur][j][nmwidx];
        if (j + w[i] <= W)
          dp[nxt][j][k] += dp[cur][j + w[i]][k];
        dp[nxt][j][k] %= mod