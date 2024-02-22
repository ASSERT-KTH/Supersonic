#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int const inf = 1 << 29;
int dp[55][3030];

int main() {
  int const MOD = 100000;

  int N, M, S;
  while (cin >> N >> M >> S && (N | M | S)) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        int currSum = add;
        int sum = 0;
        for (; currSum <= S; currSum += add) {
          sum += dp[currIndex - 1][currSum - add];
          if (sum >= MOD) sum -= MOD;
        }
        dp[currIndex][currSum - add] = sum;
      }
    }

    cout << dp[N * N][S] << endl;
  }

  return 0;
}