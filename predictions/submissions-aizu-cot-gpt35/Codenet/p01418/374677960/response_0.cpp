#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int K, R, L;
double P, E, T;
unordered_map<int, unordered_map<int, unordered_map<int, double>>> memo;

double dfs(int& d, double& l, double& r) {
  if (memo.count(d) && memo[d].count(l) && memo[d][l].count(r))
    return memo[d][l][r];

  double mid = (l + r) / 2;
  double result;

  if (!d)
    result = (T - E < mid && mid < T + E) ? 1 : 0;
  else if (r < T - E || T + E < l)
    result = 0;
  else if (mid >= T)
    result = (1.0 - P) * dfs(--d, l, mid) + P * dfs(d, mid, r);
  else
    result = (1.0 - P) * dfs(--d, mid, r) + P * dfs(d, l, mid);

  memo[d][l][r] = result;
  return result;
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}