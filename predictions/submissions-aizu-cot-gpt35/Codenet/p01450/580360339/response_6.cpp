#include <iostream>
using namespace std;

const int mod = 1000000007;
int numItems, maxWeight;
int weights[201];
int dp[2][10001][202];

int main() {
  cin >> numItems >> maxWeight;
  for (int i = 0; i < numItems; i++)
    cin >> weights[i];

  memset(dp, 0, sizeof(dp));
  dp[numItems % 2][0][numItems] = 1;

  for (int i = numItems - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;

    for (int j = 0; j < 10001; j++) {
      for (int k = 0; k <= numItems; k++) {
        dp[nxt][j][k] = 0;
        int nmwidx = k;
        if (k == numItems || weights[k] > weights[i])
          nmwidx = i;
        
        dp[nxt][j][k] += dp[cur][j][nmwidx];
        if (j + weights[i] <= maxWeight)
          dp[nxt][j][k] += dp[cur][j + weights[i]][k];

        int temp = dp[nxt][j][k] % mod;
        dp[nxt][j][k] = temp;
      }
    }
  }

  cout << dp[0][0][numItems] << endl;
  return 0;
}