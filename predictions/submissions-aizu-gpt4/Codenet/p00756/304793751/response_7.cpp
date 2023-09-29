#include <bits/stdc++.h>
using namespace std;
int n;
int x[24], y[24], r[24], c[24];
int memo[1 << 24], dp[1 << 24];
bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (!((bit >> i) & 1))
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}
int dfs(int bit) {
  if(memo[bit]) return dp[bit];
  memo[bit] = true;
  int ret = __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if (!((bit >> i) & 1) || !ok(i, bit))
      continue;
    for (int j = i + 1; j < n; j++) {
      if (!((bit >> j) & 1) || c[i] != c[j])
        continue;
      int to_bit = bit ^ (1 << i) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return dp[bit] = ret;
}
void solve() {
  fill_n(memo, 1 << n, 0);
  cout << dfs((1 << n) - 1) << endl;
}
bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}
int main() {
  while (input())
    solve();
  return 0;
}