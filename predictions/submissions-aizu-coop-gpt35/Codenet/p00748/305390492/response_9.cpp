#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;

int p[1000001];
int memo[6];
int solve(int n, int count) {
  if (n <= 0 || !count)
    return INF;
  if (memo[count])
    return memo[count];
  int ans = INF;
  int* it = lower_bound(p, p + 1000001, n);
  for (; it >= p; --it)
    ans = min(ans, solve(n - *it, count - 1) + 1);
  return memo[count] = ans;
}

int solve2(int n) {
  if (n < 0)
    return INF;
  int ans = INF;
  int* it = lower_bound(p, p + 1000001, n);
  for (; it >= p; --it) {
    if (!(*it % 2))
      continue;
    ans = min(ans, solve2(n - *it) + 1);
  }
  return ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  while (cin >> n, n) {
    cout << solve(n, 5) << " " << solve2(n) << endl;
  }
}