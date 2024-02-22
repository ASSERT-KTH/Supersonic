#include <iostream>
#define MAX 150

inline void REP(int& i, int s, int n) {
  for (i = s; i < n; i++)
    ;
}

inline void rep(int& i, int n) {
  REP(i, 0, n)
    ;
}

int main() {
  int T;
  while (std::cin >> T) {
    while (T--) {
      int dp[MAX][MAX][2] = {0};
      int N;
      std::cin >> N;
      int input[MAX];
      rep(int i, N) std::cin >> input[i];
      if (N <= 2) {
        std::cout << input[N - 1] << std::endl;
        continue;
      }
      int ans = input[N - 1];
      REP(int cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]][cur % 2] = true;
        int R = input[cur + 1];
        rep(int index, MAX * MAX * 2) {
          int L = index / (MAX * 2);
          int M = (index % (MAX * 2)) / 2;
          if (!dp[L][M][cur % 2])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) % 2] = true;
            } else
              ans = std::max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) % 2] = true;
              dp[M - 1][R + L][(cur + 1) % 2] = true;
            } else {
              ans = std::max(ans, R + L);
            }
          }
        }
      }
      std::cout << ans << std::endl;
    }
  }
  return 0;
}