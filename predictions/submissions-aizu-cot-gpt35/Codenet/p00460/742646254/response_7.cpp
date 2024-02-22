#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 100000;
const int MAX_N = 55;
const int MAX_S = 3030;

ll dp[MAX_N][MAX_S];

inline void minimize(ll &a, ll b) {
  if (b < a) {
    a = b;
  }
}

inline void maximize(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, S;
  while (cin >> N >> M >> S && (N | M | S)) {
    for (int i = 0; i <= N * N; i++) {
      for (int j = 0; j <= S; j++) {
        dp[i][j] = 0;
      }
    }

    dp[0][0] = 1;
    for (int currSum = 1; currSum <= S; currSum++) {
      for (int currIndex = 1; currIndex <= N * N; currIndex++) {
        for (int add = 1; add <= M; add++) {
          if (currSum >= add) {
            dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
          }
        }
      }
    }

    cout << dp[N * N][S] << endl;
  }

  return 0;
}