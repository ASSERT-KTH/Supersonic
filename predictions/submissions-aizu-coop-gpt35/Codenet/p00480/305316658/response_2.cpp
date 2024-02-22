#include <iostream>
#include <cstring>

using namespace std;

int a[101];
int dp[2][21];

int main() {
  int i, j;
  int N;
  cin >> N;

  memset(dp, 0, sizeof(dp));

  for (i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[1][a[1]] = 1;

  for (i = 2; i <= N; i++) {
    int prev = i % 2;
    int curr = 1 - prev;

    memset(dp[curr], 0, sizeof(dp[curr]));

    for (j = 0; j <= 20; j++) {
      int diff1 = j - a[i];
      int diff2 = j + a[i];
      if (diff1 >= 0)
        dp[curr][j] += dp[prev][diff1];
      if (diff2 <= 20)
        dp[curr][j] += dp[prev][diff2];
    }
  }

  cout << dp[N % 2][a[N]] << endl;
  return 0;
}