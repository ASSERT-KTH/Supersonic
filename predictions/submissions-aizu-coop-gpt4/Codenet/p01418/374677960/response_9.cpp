#include <bits/stdc++.h>
using namespace std;

unordered_map<double, unordered_map<double, unordered_map<int, double>>> dp; // memoization table

double dfs(int K, double L, double R, double P, double E, double T, int d, double l, double r) {
  double mid = (l + r) / 2;
  
  // Check if the result has been computed before
  if (dp.count(l) && dp[l].count(r) && dp[l][r].count(d))
    return dp[l][r][d];

  if (!d)
    return dp[l][r][d] = (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return dp[l][r][d] = 0;
  if (mid >= T)
    return dp[l][r][d] = (1.0 - P) * dfs(K, L, R, P, E, T, d - 1, l, mid) + P * dfs(K, L, R, P, E, T, d - 1, mid, r);
  
  return dp[l][r][d] = (1.0 - P) * dfs(K, L, R, P, E, T, d - 1, mid, r) + P * dfs(K, L, R, P, E, T, d - 1, l, mid);
}

int main() {
  int K, R, L;
  double P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R, P, E, T, K, L, R));
  return 0;
}