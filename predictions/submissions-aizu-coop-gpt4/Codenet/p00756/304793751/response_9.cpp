#include <bits/stdc++.h>
using namespace std;
int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24];
bool ok[24][1<<24];

void precalculateOk() {
  for (int a = 0; a < n; a++) {
    for (int bit = 0; bit < (1 << n); bit++) {
      ok[a][bit] = true;
      for (int i = 0; i < a; i++) {
        if (((bit >> i) & 1) == 0)
          continue;
        int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
        int sum = (r[i] + r[a]) * (r[i] + r[a]);
        if (dist < sum) {
          ok[a][bit] = false;
          break;
        }
      }
    }
  }
}

int dfs(int bit) {
  if(memo[bit])
    return 0;
  memo[bit] = true;
  int ret = __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || !ok[i][bit])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok[j][bit] && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  fill_n(memo, 1 << n, false);
  precalculateOk();
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