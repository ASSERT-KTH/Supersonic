#include <iostream>
using namespace std;
int a[101];
long long dp[2][21];
int main() {
  int i, j;
  int N;
  cin >> N;
  for (i = 0; i <= 20; i++) {
    dp[0][i] = 0;
  }
  for (i = 1; i <= N; i++) {
    cin >> a[i];
    for (j = 0; j <= 20; j++) {
        if (j - a[i] >= 0 && i > 1)
          dp[i%2][j] += dp[(i-1)%2][j - a[i]];
        if (j + a[i] <= 20)
          dp[i%2][j] += dp[(i-1)%2][j + a[i]];
    }
    dp[i%2][a[i]]++;
    for (j = 0; j <= 20; j++) {
        dp[(i-1)%2][j] = 0;
    }
  }
  cout << dp[N%2][0] << endl;
  return 0;
}