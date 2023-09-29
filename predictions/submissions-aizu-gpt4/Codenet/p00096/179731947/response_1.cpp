#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long dp[4001] = {1, 1};
  for (int i = 2; i <= 4000; i++) {
    dp[i] = dp[i-1] + dp[i-2];
    if (i > 1000) dp[i] -= dp[i-1001];
  }
  int n;
  while (cin >> n)
    cout << dp[n] << '\n';
  return 0;
}