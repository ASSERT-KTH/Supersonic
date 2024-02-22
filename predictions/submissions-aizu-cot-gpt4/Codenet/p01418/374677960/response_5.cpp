#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<double, double> dp;

double dfs(int K, double L, double R, double P, double E, double T, double mid) {
  if (dp.find(mid) != dp.end()) 
    return dp[mid];
    
  if (!K)
    return dp[mid] = (T - E < mid && mid < T + E) ? 1 : 0;
  if (R < T - E || T + E < L)
    return dp[mid] = 0;
  if (mid >= T)
    return dp[mid] = (1.0 - P) * dfs(K - 1, L, mid, P, E, T, (L + mid) / 2) + P * dfs(K - 1, mid, R, P, E, T, (mid + R) / 2);
  return dp[mid] = (1.0 - P) * dfs(K - 1, mid, R, P, E, T, (mid + R) / 2) + P * dfs(K - 1, L, mid, P, E, T, (L + mid) / 2);
}

int main() {
  int K, R, L;
  double P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  double mid = (L + R) / 2;
  printf("%.9f\n", dfs(K, L, R, P, E, T, mid));
  return 0;
}