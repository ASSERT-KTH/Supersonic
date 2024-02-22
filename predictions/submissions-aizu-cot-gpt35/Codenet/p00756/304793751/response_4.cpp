#include <bits/stdc++.h>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24][24];

bool ok(int bit, int a) {
  if (memo[bit][a]) {
    return true;
  }
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  memo[bit][a] = true;
  return true;
}

int dfs(int bit, int a) {
  if (memo[bit][a]) {
    return memo[bit][a];
  }
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;

  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(bit, i) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(bit, j) && dfs(to_bit, j) > ret) {
        ret = dfs(to_bit, j);
      }
    }
  }
  memo[bit][a] = ret;
  return ret;
}

void solve() {
  memset(memo, false, sizeof(memo));
  cout << dfs((1 << n) - 1, n) << endl;
}

bool input() {
  cin >> n;
  if (n <= 0)
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