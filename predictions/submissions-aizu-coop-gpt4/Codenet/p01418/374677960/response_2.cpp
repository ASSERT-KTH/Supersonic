#include <bits/stdc++.h>
using namespace std;

map<tuple<int, double, double>, double> memo;

double dfs(int d, double l, double r, double P, double E, double T) {
  auto key = make_tuple(d, l, r);
  if (memo.count(key)) return memo[key];

  double mid = (l + r) / 2;
  if (!d)
    return (abs(mid - T) < E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;

  double ret;
  if (mid >= T)
    ret = (1.0 - P) * dfs(d - 1, l, mid, P, E, T) + P * dfs(d - 1, mid, r, P, E, T);
  else
    ret = (1.0 - P) * dfs(d - 1, mid, r, P, E, T) + P * dfs(d - 1, l, mid, P, E, T);

  memo[key] = ret;
  return ret;
}

int main() {
  int K, L, R;
  double P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R, P, E, T));
  return 0;
}