#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // disable synchronization with C's standard streams
  cin.tie(NULL); // untie cin and cout
  unsigned long long dp[4001][5] = {0}; // initialize all elements to 0
  for (int i = 0; i < 5; i++)
    dp[0][i] = 1; // initialize dp[0][i] to 1
  for (int j = 1; j <= 1000; j++)
    dp[j][1] = 1; // initialize dp[j][1] to 1 if j <= 1000
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++) {
      dp[j][i] = dp[j][i-1]; // add dp[j][i-1]
      if (j > 0)
        dp[j][i] += dp[j-1][i]; // add dp[j-1][i] if j > 0
      if (j > 1000)
        dp[j][i] -= dp[j-1001][i-1]; // subtract dp[j-1001][i-1] if j > 1000
    }
  int n;
  while (cin >> n)
    cout << dp[n][4] << '\n'; // use '\n' instead of endl for faster output
  return 0;
}