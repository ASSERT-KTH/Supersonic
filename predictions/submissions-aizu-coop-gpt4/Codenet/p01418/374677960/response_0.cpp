#include <bits/stdc++.h>
using namespace std;

int K;
double L, R, P, E, T;
unordered_map<string, double> memo;

double dfs(int d, double l, double r) {
  // Convert arguments to string to use as key in memo
  string key = to_string(d) + "|" + to_string(l) + "|" + to_string(r);
  
  // If result is already computed, return it
  if (memo.count(key)) return memo[key];

  // Calculate mid inside condition blocks to avoid unnecessary computation
  if (!d) {
    double mid = (l + r) / 2;
    return (T - E < mid && mid < T + E) ? 1 : 0;
  }
  if (r < T - E || T + E < l)
    return 0;
  
  double mid = (l + r) / 2;
  double result;
  
  if (mid >= T)
    result = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    result = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
  
  // Store result in memo before returning
  memo[key] = result;
  return result;
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}