#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T;
double dp[105][1005];

double dfs(int d, double l, double r) {
  if (dp[d][r] != -1.0) {
    return dp[d][r];
  }
  
  double mid = (l + r) / 2;
  if (!d) {
    dp[d][r] = (T - E < mid && mid < T + E) ? 1.0 : 0.0;
    return dp[d][r];
  }
  
  if (r < T - E || T + E < l) {
    dp[d][r] = 0.0;
    return dp[d][r];
  }
  
  if (mid >= T) {
    dp[d][r] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  } else {
    dp[d][r] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
  }
  
  return dp[d][r];
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  
  // Initialize dp array with -1.0
  memset(dp, -1.0, sizeof(dp));
  
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}