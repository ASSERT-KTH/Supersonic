#include <iostream>

int p[1000001];
int memo[1000001][6];
int memo2[1000001];

int solve(int n) {
  if (!n)
    return 0;
  if (n <= 0)
    return 1000001;
  if (memo[n][5])
    return memo[n][5];
  int ans = 1000001;
  for (int i = 0; i <= 1000000; i++)
    ans = std::min(ans, solve(n - p[i]) + 1);
  return memo[n][5] = ans;
}

int solve2(int n) {
  if (!n)
    return 0;
  if (n < 0)
    return 1000001;
  if (memo2[n])
    return memo2[n];
  int ans = 1000001;
  for (int i = 2; i <= n; i += 2) {
    ans = std::min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (std::cin >> n, n)
    std::cout << solve(n) << " " << solve2(n) << std::endl;

  return 0;
}