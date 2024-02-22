#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];
int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = 0; p[i] <= n; i++) {
    if (p[i] > n)
      break;
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  }
  return memo[n][count] = ans;
}
int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}