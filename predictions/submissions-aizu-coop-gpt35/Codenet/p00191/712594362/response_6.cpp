#include <cmath>
#include <cstdio>
#include <iostream>

int n, m;
double dp[101][101];
double t[101][101];

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  
  if (times == m)
    return dp[times][prev] = 1;
  
  double tmp = -1;
  
  // Unroll the loop to calculate maximum probability for multiple events
  for (int i1 = 0, i2 = n; i1 < i2; i1 += 2) {
    tmp = std::max(tmp, solve(times + 1, i1) * t[prev][i1]);
    tmp = std::max(tmp, solve(times + 1, i1 + 1) * t[prev][i1 + 1]);
  }
  
  return dp[times][prev] = tmp;
}

int main(void) {
  while (std::cin >> n >> m) {
    if (!(n | m))
      break;
    
    // Manually initialize the dp array
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        dp[i][j] = -1;
      }
    }
    
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> t[i][j];
      }
    }
    retd = solve(0, 0) * 100;
    std::printf("%.2lf\n", round(retd) / 100);
  }
}