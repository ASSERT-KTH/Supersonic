#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  vector<vector<unsigned long long>> dp(1001, vector<unsigned long long>(5, 0));
  vector<unsigned long long> prefix(1001, 0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 1000; j++) {
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
      prefix[j] = (j > 0 ? prefix[j - 1] : 0) + dp[j][i];
    }
    for (int j = 0; j <= 1000; j++) {
      dp[j][i] = prefix[j];
      if (j > 1000) {
        dp[j][i] -= prefix[j - 1000 - 1];
      }
    }
  }
  int n;
  while (cin >> n)
    cout << dp[n % 1001][4] << endl;
  return 0;
}