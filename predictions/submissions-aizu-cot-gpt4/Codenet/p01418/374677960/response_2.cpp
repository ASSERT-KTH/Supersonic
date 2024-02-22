#include <bits/stdc++.h>
using namespace std;

double dfs(int d, double l, double r, double P, double E, double T, unordered_map<string, double>& memo) {
  string key = to_string(d) + to_string(l) + to_string(r);
  if (memo.count(key)) 
    return memo[key];
  
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    memo[key] = (1.0 - P) * dfs(d - 1, l, mid, P, E, T, memo) + P * dfs(d - 1, mid, r, P, E, T, memo);
  else
    memo[key] = (1.0 - P) * dfs(d - 1, mid, r, P, E, T, memo) + P * dfs(d - 1, l, mid, P, E, T, memo);
  
  return memo[key];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int K, L, R;
  double P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  
  unordered_map<string, double> memo;
  printf("%.9f\n", dfs(K, L, R, P, E, T, memo));
  return 0;
}