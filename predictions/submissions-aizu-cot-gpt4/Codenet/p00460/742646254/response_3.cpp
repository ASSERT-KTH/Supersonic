#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const inf = 1 << 29;
int dp[55][3030];
int main() {
  int const MOD = 100000;
  int N, M, S;
  while (scanf("%d %d %d", &N, &M, &S) && (N | M | S)) {
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
          if (dp[currIndex][currSum] >= MOD) dp[currIndex][currSum] -= MOD;
        }
      }
    }
    printf("%d\n", dp[N * N][S]);
  }
  return 0;
}