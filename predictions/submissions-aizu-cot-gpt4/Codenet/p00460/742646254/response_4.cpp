#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const int inf = 1 << 29;
int dp[55][3030];

bool minimize(int &a, int b) {
  return b < a && (a = b, 1);
}

bool maximize(int &a, int b) {
  return a < b && (a = b, 1);
}

int main() {
  std::ios_base::sync_with_stdio(false); cin.tie(NULL);

  const int MOD = 100000;
  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    for(int i=0; i<55; i++) {
      for(int j=0; j<3030; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for(int add = 1; add < M + 1; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}