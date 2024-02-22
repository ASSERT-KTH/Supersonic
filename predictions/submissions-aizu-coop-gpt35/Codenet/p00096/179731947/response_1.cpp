#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001 * 5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j * 5 + i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= j && k <= 1000; k++) {
        unsigned long long temp = dp[(j - k) * 5 + (i - 1)];
        dp[j * 5 + i] += temp;
      }
  int n;
  while (cin >> n)
    cout << dp[n * 5 + 4] << endl;
  return 0;
}