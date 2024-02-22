#include <iostream>
#define INF 1 << 28

int solve(int n, int count, int* p, int** memo) {
  if (n == 0)
    return 0;
  if (count == 0 || n <= 0)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = std::min(ans, solve(n - p[i], count - 1, p, memo) + 1);
  return memo[n][count] = ans;
}

int solve2(int n, int* p, int* memo2) {
  if (n == 0)
    return 0;
  if (n < 0)
    return INF;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = 1; p[i] <= n; i += 2) {
    ans = std::min(ans, solve2(n - p[i], p, memo2) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  int p[1000001];
  int memo[1000001][6] = {0};
  int memo2[1000001] = {0};

  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;

  while (std::cin >> n, n) {
    std::cout << solve(n, 5, p, memo) << " " << solve2(n, p, memo2) << std::endl;
  }

  return 0;
}