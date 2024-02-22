#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  
  // Initialize all values to 0.
  fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

  // Set dp[j][1] to 1 for j from 0 to 1000.
  fill(&dp[0][1], &dp[0][1] + 1001, 1);

  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= j; k++)
        dp[j][i] += dp[j - k][i - 1];

  vector<int> inputs;
  int n;
  while (cin >> n)
    inputs.push_back(n);
  
  for (int n : inputs)
    cout << dp[n][4] << endl;
  
  return 0;
}