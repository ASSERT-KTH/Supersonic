#include <iostream>

const int MAX_N = 1000;

int N[MAX_N];
int n;

bool solve(int m) {
  bool dp[MAX_N + 1][MAX_N + 1] = {false};

  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= N[i - 1]) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - N[i - 1]];
      }
    }
  }

  return dp[n][m];
}

int main() {
  int t;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> N[i];
  }
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    std::cin >> p;
    if (solve(p)) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }

  return 0;
}