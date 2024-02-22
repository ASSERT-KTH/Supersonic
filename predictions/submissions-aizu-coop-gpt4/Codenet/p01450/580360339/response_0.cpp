#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];

  // Initialize dp array
  dp[0][0] = 1;
  for (int i = 1; i <= W; i++)
    dp[0][i] = 0;

  int cur = 0, nxt = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) { 
      dp[nxt][j] = dp[cur][j];
      if (j + w[i] <= W)
        dp[nxt][j + w[i]] = (dp[nxt][j + w[i]] + dp[cur][j]) % mod;
    }
    swap(cur, nxt);
  }

  ll result = 0;
  for (int i = 0; i <= W; i++)
    result = (result + dp[cur][i]) % mod;

  cout << result << endl;
  return 0;
}