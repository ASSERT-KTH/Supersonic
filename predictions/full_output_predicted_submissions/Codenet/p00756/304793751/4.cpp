#include <bits/stdc++.h>
using namespace std;
int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24];
bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist <= sum)
      return false;
  }
  return true;
}
int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}
void solve() {
  fill_n(memo, 1 << n, false);
  cout << dfs((1 << n) - 1) << endl;
}
bool input