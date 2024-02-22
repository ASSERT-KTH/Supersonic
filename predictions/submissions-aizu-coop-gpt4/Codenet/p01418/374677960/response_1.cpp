#include <bits/stdc++.h>
using namespace std;
int K, R, L;
double P, E, T;
unordered_map<double, unordered_map<double, unordered_map<int, double>>> memo;

double dfs(int d, double l, double r) {
  if(memo.find(l) != memo.end() && memo[l].find(r) != memo[l].end() && memo[l][r].find(d) != memo[l][r].end())
    return memo[l][r][d];

  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    memo[l][r][d] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    memo[l][r][d] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);

  return memo[l][r][d];
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}