#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T, Q;
unordered_map<string, double> dp;

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  string state = to_string(d) + "_" + to_string(l) + "_" + to_string(r);
  
  // if state is already calculated, return it
  if(dp.find(state) != dp.end())
    return dp[state];
  
  if (!d)
    return dp[state] = (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return dp[state] = 0;
  if (mid >= T)
    return dp[state] = Q * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);

  return dp[state] = Q * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  scanf("%d %d %d %lf %lf %lf", &K, &L, &R, &P, &E, &T);
  Q = 1.0 - P;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}