#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];

void calculate_p() {
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
}

int solve(int n, int count) {
  if (n <= 0 || !count)
    return n == 0 ? 0 : INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++)
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (n <= 0)
    return n == 0 ? 0 : INF;
  if (memo[n][1])
    return memo[n][1];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    if (!(p[i] % 2))
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo[n][1] = ans;
}

int main() {
  calculate_p();
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  int n;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}