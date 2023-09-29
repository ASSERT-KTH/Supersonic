#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;

bool dp[2][MAX][MAX];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    memset(dp, false, sizeof(dp));
    int N;
    cin >> N;
    int input[N];
    rep(i, N) cin >> input[i];
    if (N <= 2) {
      cout << input[N - 1] << endl;
      continue;
    }
    int ans = input[N - 1];
    REP(cur, 1, N - 1) {
      dp[cur & 1][input[cur - 1]][input[cur]] = true;
      int R = input[cur + 1];
      rep(L, MAX) {
        rep(M, MAX) {
          if (!dp[(cur & 1) ^ 1][L][M])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[cur & 1][M][R] = true;
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[cur & 1][M][R] = true;
              dp[cur & 1][M - 1][R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
      memset(dp[(cur & 1) ^ 1], false, sizeof(dp[(cur & 1) ^ 1]));
    }
    cout << ans << endl;
  }
  return 0;
}