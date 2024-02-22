#include <iostream>
#include <climits>
#include <vector>

const int MAX = 150;

int main() {
  int T;
  while (std::cin >> T) {
    while (T--) {
      int N;
      std::cin >> N;
      std::vector<int> input(N);
      for (int i = 0; i < N; i++) {
        std::cin >> input[i];
      }

      if (N <= 2) {
        std::cout << input[N - 1] << std::endl;
        continue;
      }

      int ans = input[N - 1];
      for (int cur = 1; cur < N - 1; cur++) {
        std::vector<std::vector<std::vector<bool>>> dp(MAX, std::vector<std::vector<bool>>(MAX, std::vector<bool>(2, false)));

        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        int R = input[cur + 1];

        for (int L = 0; L < MAX; L++) {
          for (int M = 0; M < MAX; M++) {
            if (!dp[L][M][cur & 1]) {
              continue;
            }
            if (M == 0) {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
              } else {
                ans = std::max(ans, R);
              }
            } else {
              if (cur + 2 < N) {
                dp[M][R][(cur + 1) & 1] = true;
                dp[M - 1][R + L][(cur + 1) & 1] = true;
              } else {
                ans = std::max(ans, R + L);
              }
            }
          }
        }
      }

      std::cout << ans << std::endl;
    }
  }
  return 0;
}