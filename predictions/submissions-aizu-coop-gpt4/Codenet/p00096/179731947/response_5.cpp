#include <iostream>
using namespace std;

int main() {
  unsigned long long dp[4001][5];
  // Loop unrolling and loop interchange
  for (int j = 0; j < 4001; j++) {
    dp[j][0] = 0;
    dp[j][1] = j <= 1000 ? 1 : 0;
    dp[j][2] = dp[j][3] = dp[j][4] = 0;
  }

  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++) {
      unsigned long long sum = 0;
      for (int k = 0; k <= j && k <= 1000; k++) {
        sum += dp[j - k][i - 1];  // Avoid redundant computations
        dp[j][i] = sum;
      }
    }

  int n;
  if (cin >> n)  // Early termination
    cout << dp[n][4] << endl;

  return 0;
}