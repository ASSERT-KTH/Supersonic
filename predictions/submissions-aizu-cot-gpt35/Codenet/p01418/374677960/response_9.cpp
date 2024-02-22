#include <iostream>

double dfs(int d, double l, double r) {
  double mid = 0.5 * (l + r);
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    return (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  return (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  int K, L, R;
  double P, E, T;
  std::cin >> K >> L >> R >> P >> E >> T;
  std::cout.precision(9);
  std::cout << std::fixed << dfs(K, L, R) << std::endl;
  return 0;
}