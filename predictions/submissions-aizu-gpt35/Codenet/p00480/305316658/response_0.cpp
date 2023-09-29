#include <iostream>
using namespace std;
int a[101];
long long dp[21];
int main() {
  int i, j;
  int N;
  cin >> N;
  for (i = 0; i <= 20; i++) {
    dp[i] = 0;
  }
  for (i = 1; i <= N; i++) {
    cin >> a[i];
  }
  dp[a[1]] = 1;
  for (i = 2; i < N; i++) {
    for (j = 20; j >= 0; j--) {
      if (j - a[i] >= 0)
        dp[j] += dp[j - a[i]];
      if (j + a[i] <= 20)
        dp[j] += dp[j + a[i]];
    }
  }
  cout << dp[a[N]] << endl;
  return 0;
}