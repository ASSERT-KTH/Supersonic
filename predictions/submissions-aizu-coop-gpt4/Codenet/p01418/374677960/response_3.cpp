#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T;
map<pair<int, pair<double, double>>,double> dp;

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
    
  if (dp.find({d,{l,r}}) != dp.end()) // check if the result has been computed before
    return dp[{d,{l,r}}]; // return the stored result

  // compute the result and store it in the map
  double result;
  if (mid >= T)
    result = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    result = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
    
  dp[{d,{l,r}}] = result; // store the result
  return result; // return the result
}

main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
}