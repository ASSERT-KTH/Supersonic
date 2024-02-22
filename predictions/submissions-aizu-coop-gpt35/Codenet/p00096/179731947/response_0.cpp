#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  unsigned long long dp[4001][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;

  for (int j = 0; j <= 4000; j++)
    for (int i = 2; i <= 4; i++)
      for (int k = 0; k <= j && k <= 1000; k++)
        dp[j][i % 2] += dp[j - k][1 - i % 2];

  int n;
  while (cin >> n)
    cout << dp[n][4 % 2] << endl;

  return 0;
}