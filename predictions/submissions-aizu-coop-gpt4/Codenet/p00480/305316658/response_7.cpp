#include <iostream>
#include <cstring> // for memset
using namespace std;
int a[101];
long long dp[110][21];
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int N;
  cin >> N;
  memset(dp, 0, sizeof(dp)); // replace double for loop with memset
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