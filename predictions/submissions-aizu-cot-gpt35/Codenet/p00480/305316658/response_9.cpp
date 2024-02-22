#include <iostream>
using namespace std;

int a[101];
long long dp[110][21];

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[1][a[1]] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 20; j++) {
      long long prev = dp[i - 1][j];
      
      if (j - a[i] >= 0)
        dp[i][j] += prev;
      if (j + a[i] <= 20)
        dp[i][j] += prev;
    }
  }

  cout << dp[N][a[N]] << endl;
  return 0;
}