#include <iostream>
using namespace std;

const int MAXN = 100;
const int MAXM = 20;

int a[MAXN + 1];
long long dp[MAXN + 1][2 * MAXM + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[1][a[1] + MAXM] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 2 * MAXM; j++) {
      if (dp[i - 1][j] != 0) {
        if (j - a[i] >= 0) {
          dp[i][j - a[i]] += dp[i - 1][j];
        }
        if (j + a[i] <= 2 * MAXM) {
          dp[i][j + a[i]] += dp[i - 1][j];
        }
      }
    }
  }

  cout << dp[N][a[N] + MAXM] << endl;

  return 0;
}