#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T;

// This map will be used to store the results of previous computations
map<tuple<int, double, double>, double> dp;

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  
  // New: Check if the result for this state has been computed before
  auto key = make_tuple(d, l, r);
  if (dp.count(key))
    return dp[key];
  
  if (!d)
    return dp[key] = (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return dp[key] = 0;
  if (mid >= T)
    return dp[key] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  return dp[key] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}