#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 150
using namespace std;

// optimization 1: remove unused macros
// optimization 2: use std::fill to initialize the 3D array

bool dp[MAX][MAX][2];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp), false);
      int N;
      cin >> N;
      vector<int> input(N);
      for (int i = 0; i < N; ++i) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << '\n';
        continue;
      }
      int ans = input[N - 1];
      for (int cur = 1; cur < N - 1; ++cur) {
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int R = input[cur + 1];
        for (int L = 0; L < MAX; ++L) {
          for (int M = 0; M < MAX; ++M) {
            if (!dp[L][M][cur & 1]) continue;
            if (M == 0) {
              if (cur + 2 < N) dp[M][R][(cur + 1) & 1] = true;
              else ans = max(ans, R);
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
        fill(&dp[0][0][cur & 1], &dp[0][0][cur & 1] + sizeof(dp)/2, false);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}