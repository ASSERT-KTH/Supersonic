#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int* t;
int** dp;
int** tmp;

int minCost(const int &a, const int &b) {
  return (a == -1) ? b : (b == -1) ? a : (a > b) ? b : a;
}

int solve() {
  tmp = new int*[n];
  dp = new int*[n];
  for (int i = 0; i < n; i++) {
    tmp[i] = new int[2];
    dp[i] = new int[2];
    memset(tmp[i], -1, sizeof(int) * 2);
    memset(dp[i], -1, sizeof(int) * 2);
  }

  tmp[1][0] = tmp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n / 2 - 1; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              dp[j + 1][next] = minCost(dp[j + 1][next], tmp[j][pre]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre]);
          } else {
            if (next == 0)
              dp[j + 1][next] =
                  minCost(dp[j + 1][next], tmp[j][pre] + t[i - 1]);
            else
              dp[j][next] = minCost(dp[j][next], tmp[j][pre] + t[i - 1]);
          }
        }
      }
    }
    for (int j = 0; j <= n / 2 - 1; j++) {
      for (int k = 0; k < 2; k++) {
        tmp[j][k] = dp[j][k];
      }
    }
  }

  int result = minCost(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);

  for (int i = 0; i < n; i++) {
    delete[] tmp[i];
    delete[] dp[i];
  }
  delete[] tmp;
  delete[] dp;

  return result;
}

int main() {
  scanf("%d", &n);
  t = new int[n - 1];
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());

  delete[] t;

  return 0;
}