#include <iostream>
#include <vector>
using namespace std;
vector<int> a(101);
vector<vector<long long>> dp(110, vector<long long>(21));
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  dp[1][a[1]] = 1;
  for (int i = 2; i < N; i++) {
    for (int j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  cout << dp[N - 1][a[N]] << endl;
  return 0;
}