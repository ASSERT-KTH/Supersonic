#include <iostream>
const int INF = 1 << 28;

int p[1000001];
int memo[1000001][6];

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count] != -1)
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = std::min(ans, solve(n - p[i], count - 1) + 1);
  int ans2 = solve(n, 0);
  if (ans2 != INF)
    ans = std::min(ans, ans2);
  return memo[n][count] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  for (int i = 0; i <= 1000000; i++)
    for (int j = 0; j <= 5; j++)
      memo[i][j] = -1;
  while (std::cin >> n, n)
    std::cout << solve(n, 5) << " " << solve(n, 0) << std::endl;
}