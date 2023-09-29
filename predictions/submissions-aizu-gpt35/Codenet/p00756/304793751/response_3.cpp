#include <bits/stdc++.h>
using namespace std;
const int MAXN = 24;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
bool memo[1 << MAXN];
bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dx = x[i] - x[a];
    int dy = y[i] - y[a];
    int dist = dx*dx + dy*dy;
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}
int dfs(int bit, int cnt) {
  memo[bit] = true;
  int ret = n-cnt;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      continue;
    else if (ok(i, bit)) {
      int to_bit = bit | (1 << i);
      if (!memo[to_bit]) {
        ret = max(ret, dfs(to_bit, cnt+1));
      }
    }
  return ret;
}
void solve() {
  fill_n(memo, 1 << n, false);
  cout << dfs(0,0) << endl;
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