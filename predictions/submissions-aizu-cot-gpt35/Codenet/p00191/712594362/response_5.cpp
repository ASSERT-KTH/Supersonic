#include <iostream>

const int MAX_N = 101;
int n, m;
int dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times >= m)
    return dp[times][prev] = 1;

  int tmp = -1;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = std::max(tmp, solve(times + 1, i));
    } else {
      tmp = std::max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}

int main() {
  while (std::cin >> n >> m) {
    if (!(n | m))
      break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }

    for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
        dp[i][j] = -1;
      }
    }

    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
  return 0;
}