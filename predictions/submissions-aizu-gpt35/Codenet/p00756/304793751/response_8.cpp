#include <bits/stdc++.h>
using namespace std;
int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24];
bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dx = x[i] - x[a], dy = y[i] - y[a];
    int dist = dx * dx + dy * dy;
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}
int dfs(int bit) {
  memo[bit] = true;
  int ret = n - __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) {
      for (int j = i + 1; j < n; j++) {
        if ((bit >> j) & 1 && c[i] == c[j]) {
          int to_bit = bit & ~(1 << i) & ~(1 << j);
          if (ok(i, to_bit) && ok(j, to_bit) && !memo[to_bit]) {
            ret = max(ret, dfs(to_bit));
          }
        }
      }
      break;
    }
  }
  return ret;
}
void solve() {
  fill_n(memo, 1 << n, false);
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