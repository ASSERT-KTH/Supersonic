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
bool dp[2][MAX][MAX], cur;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
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
    cur = 0;
    dp[0][input[0]][input[1]] = true;
    REP(turn, 1, N - 2) {
      cur ^= 1;
      memset(dp[cur], false, sizeof(dp[cur]));
      int R = input[turn + 1];
      rep(L, MAX) {
        rep(M, MAX) {
          if (!dp[cur ^ 1][L][M])
            continue;
          if (M == 0) {
            if (turn + 2 < N) {
              dp[cur][M][R] = true;
            } else
              ans = max(ans, R);
          } else {
            if (turn + 2 < N) {
              dp[cur][M][R] = true;
              dp[cur][M - 1][R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}