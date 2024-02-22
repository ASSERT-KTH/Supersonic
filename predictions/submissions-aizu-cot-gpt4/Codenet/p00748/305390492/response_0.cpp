#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
const int INF = INT_MAX;
int p[181]; // 181 is enough as p[181] > 10^6
int memo[1000001][6];
int memo2[1000001];

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INF;
  if (memo[n][count] != -1)
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
  if (memo2[n] != -1)
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
  int n, i = 0;
  fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(memo[0][0]), -1);
  fill(memo2, memo2 + sizeof(memo2) / sizeof(memo2[0]), -1);
  while ((p[i] = i * (i + 1) * (i + 2) / 6) <= 1000000) i++;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}