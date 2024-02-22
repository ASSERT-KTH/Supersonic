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

bool dp[MAX][MAX];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      memset(dp, false, sizeof(dp)); // Initialize dp array to false

      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 0, N - 1) { // Reduce loop range from 1 to N-1 to 0 to N-2
        dp[input[cur]][input[cur + 1]] = true; // Store intermediate result directly in dp array
        int R = input[cur + 2]; // Optimize loop unrolling by using cur+2 instead of cur+1
        rep(L, MAX) {
          rep(M, MAX) {
            bool dpResult = dp[L][M]; // Store the result of dp condition
            if (!dpResult) continue; // Use the stored result directly in loop condition
            if (M == 0) {
              if (cur + 3 < N) {
                dp[M][R] = true;
              } else
                ans = max(ans, R);
            } else {
              if (cur + 3 < N) {
                dp[M][R] = true;
                dp[M - 1][R + L] = true;
              } else {
                ans = max(ans, R + L);
              }
            }
          }
        }
        memset(dp, false, sizeof(dp)); // Reset dp array using memset
      }
      cout << ans << endl;
    }
  }
  return 0;
}