#include <algorithm>
#include <iostream>
#include <unordered_map>
#define INF 1 << 28
using namespace std;

int p[1000001];
unordered_map<int, unordered_map<int, int>> memo; // Optimization: Use unordered_map for memoization

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    if (p[i] > n) // Optimization: Break out of loop when p[i] exceeds n
      break;
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  }
  return memo[n][count] = ans;
}

unordered_map<int, int> memo2; // Optimization: Use unordered_map for memoization

int solve2(int n) {
  if (!n)
    return 0;
  if (n < 0)
    return INF;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    if (!(p[i] % 2))
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}