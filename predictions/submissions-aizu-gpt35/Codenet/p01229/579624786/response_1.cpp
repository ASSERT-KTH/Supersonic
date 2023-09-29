#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;
bool dp[2][MAX][MAX];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) dp[0][i][j] = false;
      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      int cur = 1;
      dp[0][input[cur - 1]][input[cur]] = true;
      int R = input[cur + 1];
      rep(L, MAX) {
        rep(M, MAX) {
          if (!dp[0][L][M])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[1][M][R] = true;
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[1][M][R] = true;
              dp[1][M - 1][R + L] = true;
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
      cur++;
      rep(i, MAX) rep(j, MAX) dp[0][i][j] = false;
      while (cur < N - 1) {
        R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[1][L][M])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[0][M][R] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[0][M][R] = true;
                dp[0][M - 1][R + L] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        cur++;
        rep(i, MAX) rep(j, MAX) dp[1][i][j] = false;
        swap(dp[0], dp[1]);
      }
      cout << ans << endl;
    }
  }
  return 0;
}