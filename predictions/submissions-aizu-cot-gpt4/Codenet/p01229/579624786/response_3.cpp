#include <algorithm>
#include <iostream>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;

bool dp[MAX][MAX];
int input[MAX];

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) dp[i][j] = false;
      int N;
      cin >> N;
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]] = true;
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M])
              continue;
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
            dp[L][M] = false;
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}