#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int* a = new int[N + 1];
  long long** dp = new long long*[N];
  for(int i = 0; i < N; i++) dp[i] = new long long[21]();

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[0][a[1]] = 1;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
    if(i >= N - 1) break;
  }

  cout << dp[N - 1][a[N]] << endl;

  for(int i = 0; i < N; i++) delete[] dp[i];
  delete[] dp;
  delete[] a;

  return 0;
}