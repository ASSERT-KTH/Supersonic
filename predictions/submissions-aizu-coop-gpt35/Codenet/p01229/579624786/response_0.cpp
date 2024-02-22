#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;
bool dp[MAX][MAX];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = 0;
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        REP(L, 0, input[cur]) {
          REP(M, 0, input[cur + 1]) {
            if (!dp[L][M])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R] = true;
              } else
                ans = (R > ans) ? R : ans;
            } else {
              if (cur + 2 < N) {
                dp[M][R] = true;
                dp[M - 1][R + L] = true;
              } else {
                ans = (R + L > ans) ? R + L : ans;
              }
            }
          }
        }
        REP(i, 0, input[cur]) REP(j, 0, input[cur + 1]) dp[i][j] = false;
      }
      cout << ans << endl;
    }
  }
  return 0;
}