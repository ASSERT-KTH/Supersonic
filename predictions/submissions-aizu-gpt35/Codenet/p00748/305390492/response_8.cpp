#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;

vector<int> p;
vector<int> memo(1000001 * 6);
vector<int> memo2(1000001);

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n * 6 + count])
    return memo[n * 6 + count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  return memo[n * 6 + count] = ans;
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
  for (int i = 0; i <= 1000000; i++)
    p.push_back(i * (i + 1) * (i + 2) / 6);
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}