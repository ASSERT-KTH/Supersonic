#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 28
using namespace std;
vector<int> p(1000001);
vector<vector<int>> memo(1000001, vector<int>(6));
vector<int> memo2(1000001);

int solve(const int &n, const int &count) {
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

int solve2(const int &n) {
  if (!n)
    return 0;
  if (n < 0)
    return INF;
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) / 2;
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  int n;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << "\n";
}