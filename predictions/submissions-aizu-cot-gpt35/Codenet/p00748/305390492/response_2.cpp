#include <iostream>
#include <vector>

constexpr int INF = 1 << 28;

std::vector<int> p;
std::vector<std::vector<int>> memo;
std::vector<int> memo2;

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n && count > 0; i++)
    ans = std::min(ans, solve(n - p[i], count - 1) + 1);
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (!n)
    return 0;
  if (n < 0)
    return INF;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    ans = std::min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}

void initializeP() {
  p.resize(1000001);
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
}

int main() {
  initializeP();
  
  memo.resize(1000001, std::vector<int>(6));
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
    
  int n;
  while (std::cin >> n, n)
    std::cout << solve(n, 5) << " " << solve2(n) << std::endl;
}