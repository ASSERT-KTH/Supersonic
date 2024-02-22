#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned long long dp[1001][5];
  for (int j = 0; j < 1001; j++) {
    dp[j][0] = 0;
    dp[j][1] = j <= 1000 ? 1 : 0;
  }
  
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j < 1001; j++)
      for (int k = 0; k <= j && k <= 1000; k++)
        dp[j][i] += dp[j - k][i - 1];

  int n;
  while (cin >> n)
    cout << dp[n % 1001][4] << "\n";
  
  return 0;
}