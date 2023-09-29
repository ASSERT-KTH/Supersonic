#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];
int solve(int n, int count) {
  if (n <= 0)
    return n ? INF : 0;
  if (!count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  return memo[n][count] = ans;
}
int solve2(int n) {
  if (n < 0)
    return n ? INF : 0;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    if (!(p[i] & 1))
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) / 2;
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << "\n";
}