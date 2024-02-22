#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

int a[101];
long long dp[110][21];

int main() {
  memset(dp, 0, sizeof(dp));

  int N;
  cin >> N;

  string line;
  getline(cin, line);
  stringstream ss(line);
  for (int i = 1; i <= N; i++) {
    ss >> a[i];
  }

  dp[1][a[1]] = 1;
  for (int i = 2; i < N; i++) {
    for (int j = 0; j <= 20; j++) {
      if (abs(j - a[i]) <= 20) {
        dp[i][j] += dp[i - 1][j - a[i]];
        dp[i][j] += dp[i - 1][j + a[i]];
      }
    }
  }

  cout << dp[N - 1][a[N]] << endl;
  return 0;
}