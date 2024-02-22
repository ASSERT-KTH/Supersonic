#include <cstring>
#include <iostream>
using namespace std;

unsigned long long dp[4001][5];

void calculate_dp() {
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j <= 1000; j++)
    dp[j][1] = 1;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= j && k <= 1000; k++)
        dp[j][i] += dp[j - k][i - 1];
}

int main() {
  calculate_dp();
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}