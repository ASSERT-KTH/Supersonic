#include <iostream>
#include <cstdio>

double dfs(int d, double l, double r, double T, double E, double P) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    return (1.0 - P) * dfs(d - 1, l, mid, T, E, P) + P * dfs(d - 1, mid, r, T, E, P);
  return (1.0 - P) * dfs(d - 1, mid, r, T, E, P) + P * dfs(d - 1, l, mid, T, E, P);
}

int main() {
  int K, L, R;
  double P, E, T;
  std::cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R, T, E, P));
  return 0;
}