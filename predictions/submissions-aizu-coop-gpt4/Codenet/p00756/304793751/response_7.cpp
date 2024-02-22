#include <bits/stdc++.h>
using namespace std;

const int MAXN = 24;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
bool memo[1 << MAXN];
int dist[MAXN][MAXN], sum[MAXN][MAXN];

bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    if (dist[i][a] < sum[i][a])
      return false;
  }
  return true;
}

int dfs(int bit) {
  if (memo[bit]) return 0;
  memo[bit] = true;
  int ret = __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit)) {
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

bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i] >> c[i];
    for (int j = 0; j < i; j++) {
      dist[j][i] = dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      sum[j][i] = sum[i][j] = (r[i] + r[j]) * (r[i] + r[j]);
    }
  }
  return true;
}

int main() {
  while (input())
    solve();
  return 0;
}