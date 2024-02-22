#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;
bool dp[MAX][MAX][2];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(NULL);
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << "\n";
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        int curPlusOneMod = (cur + 1) & 1;
        int curMod = cur & 1;
        dp[input[cur - 1]][input[cur]][curMod] = true;
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M][curMod])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][curPlusOneMod] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[M][R][curPlusOneMod] = true;
                dp[M - 1][R + L][curPlusOneMod] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        rep(i, MAX) rep(j, MAX) dp[i][j][curMod] = false;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}