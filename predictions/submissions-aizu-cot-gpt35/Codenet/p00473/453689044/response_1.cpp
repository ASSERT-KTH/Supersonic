#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);

  int* t = new int[n - 1];
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }

  int* dp = new int[n / 2 + 1];
  int* tmp = new int[n / 2 + 1];

  std::fill(tmp, tmp + n / 2 + 1, 0);

  for (int i = 1; i < n; i++) {
    std::swap(dp, tmp);
    std::fill(dp, dp + n / 2 + 1, -1);

    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j] != -1) {
          for (int next = 0; next < 2; next++) {
            if (pre == next) {
              if (next == 0)
                dp[j + 1] = std::min(dp[j + 1], tmp[j]);
              else
                dp[j] = std::min(dp[j], tmp[j]);
            } else {
              if (next == 0)
                dp[j + 1] = std::min(dp[j + 1], tmp[j] + t[i - 1]);
              else
                dp[j] = std::min(dp[j], tmp[j] + t[i - 1]);
            }
          }
        }
      }
    }
  }

  int result = std::min(dp[n / 2], dp[n / 2 + 1]);
  printf("%d\n", result);

  delete[] t;
  delete[] dp;
  delete[] tmp;

  return 0;
}