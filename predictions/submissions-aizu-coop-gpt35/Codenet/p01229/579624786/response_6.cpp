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
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        for (int L = 0; L <= input[cur]; L++) {
          for (int M = 0; M <= input[cur + 1]; M++) {
            if (!dp[L][M]) continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 2 < N) {
                dp[M][R] = true;
                dp[M - 1][R + L] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        rep(i, MAX) rep(j, MAX) dp[i][j] = false;
      }
      cout << ans << endl;
    }
  }
  return 0;
}