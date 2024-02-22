#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
  unsigned long long dp[4001][5];
  memset(dp, 0, sizeof(dp));
  
  dp[0][1] = 1;
  for (int i = 1; i <= 1000; i++)
    dp[i][1] = 1;
  
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++) {
      dp[j][i] = dp[j][i-1];
      if(j >= i)
        dp[j][i] += dp[j - i][i];
    }
  
  int n;
  string output = "";
  while (cin >> n)
    output += to_string(dp[n][4]) + "\n";

  cout << output;
  return 0;
}