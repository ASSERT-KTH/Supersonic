#include <iostream>
using namespace std;
int a[101];
long long dp[110][21];

int main() {
  int N;
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  
  for (int j = 0; j <= 20; j++) {
    dp[0][j] = 0;
  }
  
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    dp[i][0] = 0;
    dp[i][a[i]] = 1;
    for (int j = 1; j <= 20; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  cout << dp[N - 1][a[N]] << endl;
  return 0;
}