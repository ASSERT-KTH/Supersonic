#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150

using namespace std;

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int input[N];
      
      // Read input values
      rep(i, N) cin >> input[i];

      // Initialize dp array dynamically
      bool*** dp = new bool**[N];
      rep(i, N) {
        dp[i] = new bool*[MAX];
        rep(j, MAX) {
          dp[i][j] = new bool[MAX];
          rep(k, 2) {
            dp[i][j][k] = false;
          }
        }
      }

      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }

      int ans = input[N - 1];

      // Initialize dp array for the first element
      dp[0][0][0] = true;
      dp[0][0][1] = true;

      REP(cur, 1, N - 1) {
        int R = input[cur + 1];

        // Iterate over the dp array
        rep(L, MAX) {
          rep(M, MAX) {
            if (!dp[cur - 1][L][M])
              continue;
            if (M == 0) {
              if (cur + 2 < N) {
                dp[cur][R][M] = true;
              } else {
                ans = max(ans, R);
              }
            } else {
              if (cur + 2 < N) {
                dp[cur][R][M] = true;
                dp[cur][R + L][M - 1] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
      }

      // Deallocate dp array
      rep(i, N) {
        rep(j, MAX) {
          delete[] dp[i][j];
        }
        delete[] dp[i];
      }
      delete[] dp;

      cout << ans << endl;
    }
  }
  return 0;
}