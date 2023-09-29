#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  sort(w, w + N);
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    int cur = i % 2;
    int nxt = (i + 1) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = dp[cur][j];
      if (j + w[i] <= W)
        dp[nxt][j + w[i]] += dp[cur][j];
      dp[nxt][j] %= mod;
      dp[nxt][j + w[i]] %= mod;
    }
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}