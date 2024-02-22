#include <iostream>

constexpr int INF = 1 << 28;
constexpr int MAX_N = 1000000;
int p[MAX_N + 1];
int memo[MAX_N + 1][6];

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n < 0 || !count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n && i <= MAX_N; i++)
    ans = std::min(ans, solve(n - p[i], count - 1) + 1);
  return memo[n][count] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= MAX_N; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  while (std::cin >> n, n)
    std::cout << solve(n, 5) << " " << solve(n, 5) << std::endl;
}