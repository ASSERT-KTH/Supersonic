#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150

using namespace std;

unsigned char dp[MAX][MAX][2];

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) rep(l, 2) dp[i][j][l] = 0;
      int N;
      cin >> N;
      vector<int> input(N);
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      int curAnd1 = 0;
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]][curAnd1] = 1;
        rep(L, input[cur]) {
          rep(M, MAX) {
            if (!dp[L][M][curAnd1])
              continue;
            if (M == 0) {
              dp[M][input[cur + 1]][curAnd1 ^ 1] = 1;
              if (cur + 2 == N)
                ans = max(ans, input[cur + 1]);
            } else {
              dp[M][input[cur + 1]][curAnd1 ^ 1] = 1;
              dp[M - 1][input[cur + 1] + L][curAnd1 ^ 1] = 1;
              if (cur + 2 == N)
                ans = max(ans, input[cur + 1] + L);
            }
          }
        }
        rep(i, MAX) rep(j, MAX) dp[i][j][curAnd1] = 0;
        curAnd1 ^= 1;
      }
      cout << ans << endl;
    }
  }
  return 0;
}