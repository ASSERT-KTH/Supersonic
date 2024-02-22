#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;
int p[1000001];
vector<int> memo(1000001);
int solve(int n, int count) {
  if (!n)
    return 0;
  if (memo[n])
    return memo[n];
  int ans = INF;
  for (int i = 0; i <= n; i+=6) {
    ans = min(ans, solve(n - p[i], count - 1) + 1);
    ans = min(ans, solve(n - p[i + 1], count - 1) + 1);
    ans = min(ans, solve(n - p[i + 2], count - 1) + 1);
    ans = min(ans, solve(n - p[i + 3], count - 1) + 1);
    ans = min(ans, solve(n - p[i + 4], count - 1) + 1);
    ans = min(ans, solve(n - p[i + 5], count - 1) + 1);
  }
  return memo[n] = ans;
}
int solve2(int n) {
  if (!n)
    return 0;
  if (memo[n])
    return memo[n];
  int ans = INF;
  for (int i = 0; i <= n; i+=6) {
    if (!(p[i] % 2))
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
    ans = min(ans, solve2(n - p[i + 1]) + 1);
    ans = min(ans, solve2(n - p[i + 2]) + 1);
    ans = min(ans, solve2(n - p[i + 3]) + 1);
    ans = min(ans, solve2(n - p[i + 4]) + 1);
    ans = min(ans, solve2(n - p[i + 5]) + 1);
  }
  return memo[n] = ans;
}
int main() {
  #pragma GCC optimize("O3")
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}