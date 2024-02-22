#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++) {
    unsigned long long prefix_sum = 0; // we will store the prefix sum here
    for (int j = 0; j <= 4000; j++) {
      if (j > 1000) prefix_sum -= dp[j - 1001][i - 1]; // subtract the value that is no longer in the range
      prefix_sum += dp[j][i - 1]; // add the current value to the prefix sum
      dp[j][i] += prefix_sum;
    }
  }
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}