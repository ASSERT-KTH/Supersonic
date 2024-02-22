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
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) rep(l, 2) dp[i][j][l] = false;
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
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M][cur & 1])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
                dp[M - 1][R + L][(cur + 1) & 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        rep(i, MAX) rep(j, MAX) dp[i][j][cur & 1] = false;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
