#include <cstdio>

typedef long long ll;
const int inf = 1 << 29;
const int MOD = 100000;
const int MAXN = 55;
const int MAXS = 3030;
int dp[MAXN][MAXS];

inline bool minimize(int &a, int b) {
  return b < a && (a = b, true);
}

inline bool maximize(int &a, int b) {
  return a < b && (a = b, true);
}

inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int N, M, S;
  while (scanf("%d %d %d", &N, &M, &S) != EOF && (N || M || S)) {
    for(int i=0; i<MAXN; i++)
      for(int j=0; j<MAXS; j++)
        dp[i][j] = 0;

    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum += 4) {
          add(dp[currIndex][currSum], dp[currIndex - 1][currSum - add]);
          if (currSum + 1 <= S) add(dp[currIndex][currSum + 1], dp[currIndex - 1][currSum + 1 - add]);
          if (currSum + 2 <= S) add(dp[currIndex][currSum + 2], dp[currIndex - 1][currSum + 2 - add]);
          if (currSum + 3 <= S) add(dp[currIndex][currSum + 3], dp[currIndex - 1][currSum + 3 - add]);
        }
      }
    }
    printf("%d\n", dp[N * N][S]);
  }
  return 0;
}