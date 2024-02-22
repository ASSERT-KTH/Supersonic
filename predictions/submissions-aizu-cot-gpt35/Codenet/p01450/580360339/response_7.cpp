#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAX_NUM_WEIGHTS = 201;
const int MAX_TOTAL_WEIGHT = 10001;

int main() {
  int numWeights, weightLimit;
  cin >> numWeights >> weightLimit;

  int weights[MAX_NUM_WEIGHTS];
  for (int i = 0; i < numWeights; i++)
    cin >> weights[i];

  ll dp[2][MAX_TOTAL_WEIGHT][MAX_NUM_WEIGHTS];
  memset(dp, 0, sizeof(dp));

  for (int j = 0; j <= weightLimit; j++) {
    for (int k = numWeights; k >= 0; k--) {
      if (j <= weightLimit && (k == numWeights || weights[k] + j > weightLimit))
        dp[numWeights % 2][j][k] = 1;
      else
        dp[numWeights % 2][j][k] = 0;
    }
  }

  for (int i = numWeights - 1; i >= 0; i--) {
    int idx = (i + 1) % 2;
    for (int j = 0; j <= weightLimit; j++) {
      for (int k = numWeights; k >= 0; k--) {
        dp[idx][j][k] = 0;
        int nmwidx = k;
        if (k == numWeights || weights[k] > weights[i])
          nmwidx = i;
        dp[idx][j][k] += dp[(idx + 1) % 2][j][nmwidx];
        if (j + weights[i] <= weightLimit)
          dp[idx][j][k] += dp[(idx + 1) % 2][j + weights[i]][k];
        dp[idx][j][k] %= mod;
      }
    }
  }

  cout << dp[0][0][numWeights] << endl;
  return 0;
}