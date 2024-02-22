#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
double dp[MAX][MAX][MAX]; // assuming the maximum value of d, l and r will be 100.
int K, R, L;
bool calculated[MAX][MAX][MAX] = {false}; // to keep track of the calculated results
double P, E, T;
double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (calculated[d][l][r]) // if the result is already calculated, return it
    return dp[d][l][r];
  if (mid >= T)
    dp[d][l][r] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    dp[d][l][r] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
  calculated[d][l][r] = true; // mark the result as calculated
  return dp[d][l][r];
}
main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
}