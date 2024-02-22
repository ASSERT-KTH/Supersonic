#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;
bool dp[MAX][MAX][2];
int main() {
  ios_base::sync_with_stdio(false); // to speed up I/O operations
  cin.tie(NULL); // untie cin and cout ties to speed up I/O operations
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N);
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << "\n";
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        int curBit = cur & 1;
        dp[input[cur - 1]][input[cur]][curBit] = true;
        int R = input[cur + 1];
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[L][M][curBit])
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
        rep(i, MAX) rep(j, MAX) dp[i][j][curBit] = false;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}