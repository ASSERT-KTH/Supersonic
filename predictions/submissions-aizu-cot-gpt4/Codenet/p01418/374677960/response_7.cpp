#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
using namespace std;

int K, R, L;
double P, E, T;
map<pair<double, double>, double> memo;

double dfs(int d, double l, double r) {
  if (memo.find(make_pair(l, r)) != memo.end()) {
    return memo[make_pair(l, r)];
  }

  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    memo[make_pair(l, r)] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    memo[make_pair(l, r)] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);

  return memo[make_pair(l, r)];
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}