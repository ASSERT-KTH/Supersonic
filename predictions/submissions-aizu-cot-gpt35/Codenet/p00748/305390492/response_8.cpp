#include <iostream>
#include <vector>

const int INF = 1 << 28;

int solve(int n, int count, std::vector<int>& memo, const std::vector<int>& p) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n])
    return memo[n];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = std::min(ans, solve(n - p[i], count - 1, memo, p) + 1);
  return memo[n] = ans;
}

int solve2(int n, std::vector<int>& memo2, const std::vector<int>& p) {
  if (!n)
    return 0;
  if (n < 0)
    return INF;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = 0; p[i] <= n; i += 2)
    ans = std::min(ans, solve2(n - p[i], memo2, p) + 1);
  return memo2[n] = ans;
}

int main() {
  int n;
  std::vector<int> p(1000001);
  std::vector<int> memo(1000001);
  std::vector<int> memo2(1000001);
  
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  
  for (int i = 1; i <= 1000000; i++) {
    solve2(i, memo2, p);
  }
  
  while (std::cin >> n, n) {
    std::cout << solve(n, 5, memo, p) << " " << solve2(n, memo2, p) << std::endl;
  }
  
  return 0;
}