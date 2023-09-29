#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = min(ans, solve(n - p[i], count - 1) + 1);
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
    if (!(p[i] % 2))
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}
int main() {
  int n;
  while (cin >> n, n)
    solve(n, 5);
}
