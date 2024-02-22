#include <iostream>
using namespace std;

int a[101];
long long dp[21];

int main() {
  int N;
  cin >> N;

  for (int j = 0; j <= 20; j++) {
    dp[j] = 0;
  }

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[a[1]] = 1;

  for (int i = 2; i < N; i++) {
    long long temp[21] = {0};

    for (int j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        temp[j] += dp[j - a[i]];
      if (j + a[i] <= 20)
        temp[j] += dp[j + a[i]];
    }

    for (int j = 0; j <= 20; j++) {
      dp[j] = temp[j];
    }
  }

  cout << dp[a[N]] << endl;

  return 0;
}