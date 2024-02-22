#include <cstdio>
#include <iostream>
#include <iomanip>

const int MAX_N = 101;
double dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double solve(int n, int m) {
  for (int times = m; times >= 0; times--) {
    for (int prev = 0; prev < n; prev++) {
      if (times == m) {
        dp[times][prev] = 1.0;
      } else {
        double tmp = -1.0;
        for (int i = 0; i < n; i++) {
          if (times == 0) {
            tmp = std::max(tmp, solve(n, m - 1) * 1.0);
          } else {
            tmp = std::max(tmp, solve(n, m - 1) * t[prev][i]);
          }
        }
        dp[times][prev] = tmp;
      }
    }
  }
  return dp[0][0];
}

int main(void) {
  int n, m;
  while (std::cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }
    
    for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
        dp[i][j] = -1.0;
      }
    }
    
    double result = solve(n, m);
    double roundedResult = std::round(result * 100) / 100;
    std::cout << std::fixed << std::setprecision(2) << roundedResult << std::endl;
  }
  return 0;
}