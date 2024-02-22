#include <iostream>
#include <cstdio>
#include <cmath>

double dfs(int d, int l, int r, double mid) {
  if (d == 0)
    return (std::abs(mid - T) < E) ? 1 : 0;

  if (r < T - E || T + E < l)
    return 0;

  double result = 0;
  while (l <= r) {
    if (mid >= T)
      result += (1.0 - P) * dfs(d - 1, l, mid, (l + mid) / 2) + P * dfs(d - 1, mid, r, (mid + r) / 2);
    else
      result += (1.0 - P) * dfs(d - 1, mid, r, (mid + r) / 2) + P * dfs(d - 1, l, mid, (l + mid) / 2);

    l++;
    r--;
  }

  return result;
}

int main() {
  int K, R, L;
  double P, E, T;
  std::cin >> K >> L >> R >> P >> E >> T;
  std::cout.precision(9);
  std::cout << std::fixed << dfs(K, L, R, (L + R) / 2) << std::endl;

  return 0;
}