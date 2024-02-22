#include <iostream>
const int INF = 1 << 28;
int p[1000001];

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  static int memo[1000001][6];
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  int start = 0;
  for (int i = 0; p[i] <= n; i++) {
    ans = std::min(ans, solve(n - p[i], count - 1) + 1);
    start = i;
  }
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (!n)
    return 0;
  if (n < 0)
    return INF;
  static int memo2[1000001];
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  int start = 0;
  for (int i = 0; p[i] <= n; i++) {
    ans = std::min(ans, solve2(n - p[i]) + 1);
    start = i;
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  while (std::cin >> n, n)
    std::cout << solve(n, 5) << " " << solve2(n) << std::endl;
}