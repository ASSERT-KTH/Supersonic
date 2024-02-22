#include <cstdio>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define MAX 150
bool dp[MAX][MAX][2];

int main() {
  int T;
  while (scanf("%d", &T)) {
    while (T--) {
      for (int i = MAX; --i >= 0; ) {
        for (int j = MAX; --j >= 0; ) {
          for (int l = 2; --l >= 0; ) {
            dp[i][j][l] = false;
          }
        }
      }
      int N;
      scanf("%d", &N);
      int input[N];
      for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
      }
      if (N <= 2) {
        printf("%d\n", input[N - 1]);
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int R = input[cur + 1];
        for (int L = MAX; --L >= 0; ) {
          for (int M = MAX; --M >= 0; ) {
            if (!dp[L][M][cur & 1])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
              } else
                ans = ((ans) > (R) ? (ans) : (R));
            } else {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
                dp[M - 1][R + L][(cur + 1) & 1] = true;
              } else {
                ans = ((ans) > (R + L) ? (ans) : (R + L));
              }
            }
          }
        }
        for (int i = MAX; --i >= 0; ) {
          for (int j = MAX; --j >= 0; ) {
            dp[i][j][cur & 1] = false;
          }
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}