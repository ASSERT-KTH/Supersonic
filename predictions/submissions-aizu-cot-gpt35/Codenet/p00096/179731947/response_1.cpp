#include <iostream>
using namespace std;

int main() {
  unsigned int dp[4001];
  for (int j = 0; j <= 4000; j++)
    dp[j] = (j <= 1000) ? 1 : 0;
  for (int k = 2; k <= 4; k++) {
    for (int j = 0; j <= 4000; j++) {
      unsigned int prefixSum = 0;
      for (int i = 0; i <= j && i <= 1000; i++) {
        prefixSum += dp[j - i];
        dp[j] = prefixSum;
      }
    }
  }
  int n;
  while (cin >> n)
    cout << dp[n] << endl;
  return 0;
}