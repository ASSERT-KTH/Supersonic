#include <algorithm>
#include <cstdio>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;
bool dp[MAX][MAX];
bool visited[MAX][MAX];
int testcase[MAX];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%d", &testcase[i]);
    int ans = testcase[N - 1];
    REP(cur, 1, N - 1) {
      if (!visited[testcase[cur - 1]][testcase[cur]]) {
        dp[testcase[cur - 1]][testcase[cur]] = true;
        visited[testcase[cur - 1]][testcase[cur]] = true;
      }
      int R = testcase[cur + 1];
      rep(L, MAX) {
        rep(M, MAX) {
          if (!dp[L][M]) continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R] = true;
            } else {
              ans = (R > ans ? R : ans);
            }
          } else {
            if (cur + 2 < N) {
              dp[M][R] = true;
              dp[M - 1][R + L] = true;
            } else {
              int temp = R + L;
              ans = (temp > ans ? temp : ans);
            }
          }
        }
      }
    }
    printf("%d\n", ans);
    rep(i, MAX) rep(j, MAX) if (visited[i][j]) dp[i][j] = visited[i][j] = false;
  }
  return 0;
}